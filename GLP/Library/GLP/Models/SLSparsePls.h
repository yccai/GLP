//
//  SLSparsePls.h
//  GLP
//
//  Created by Zheng Shao on 12/20/12.
//  Copyright (c) 2012 Saigo Laboratoire. All rights reserved.
//
//  This is free software with ABSOLUTELY NO WARRANTY.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA
//

#ifndef GLP_SLSparsePls_h
#define GLP_SLSparsePls_h

#include <iostream>
#include <cstdio>
#include "SLModelStrategy.h"
#include "SLModel.h"

class SLSparsePls;

template <typename D>
class IMode
{
public:
    D* dataSource;
    
public:
    virtual bool checkReponseData() = 0;
    virtual SLMODELRESULTYPE getResultType() = 0;
};

template <typename D>
class IColumnSelection
{
public:
    D* dataSource;

public:
    virtual MatrixXd getSelectedColumn() = 0;
};

class SLPlsModeRregession : public IMode<SLSparsePls>
{
    virtual bool checkReponseData();
    virtual SLMODELRESULTYPE getResultType();
};

class SLPlsModeClassification : public IMode<SLSparsePls>
{
    virtual bool checkReponseData();
    virtual SLMODELRESULTYPE getResultType();
};

class SLPlsColumnSelectionAverage : public IColumnSelection<SLSparsePls>
{
    virtual MatrixXd getSelectedColumn();
};

class SLPlsColumnSelectionRandom : public IColumnSelection<SLSparsePls>
{
    virtual MatrixXd getSelectedColumn();
};

class SLPlsColumnSelectionVariance : public IColumnSelection<SLSparsePls>
{
    virtual MatrixXd getSelectedColumn();
};

class SLSparsePls : public SLModelStrategy
{
public:
    class SLSparsePlsParameters
    {
    public:
        SLSparsePlsParameters() :
            verbose(false),
            mode(NULL),
            colMode(NULL),
            randIndex(0) {}
        
    public:
        bool verbose;
        IMode<SLSparsePls>* mode;
        IColumnSelection<SLSparsePls>* colMode;
        int randIndex;
    };
    
public:
    SLSparsePls() {};
        
    /* Train: Sparse PLS regression: Y = XB
     * Input
     *      X: the X matrix which need be appended
     *      Y: assignable when the inside Y did not be initialized.
     *   type: type of results
     *
     * Return: the results stored in mapped structure.
     */
    virtual SLModelResult train(const MatrixXd& appendedX, const MatrixXd& theY, SLMODELRESULTYPE type);

    /* Classify:
     * Input
     *     tX: X matrix of test data
     *     tY: Y matrix of test data
     *   type: type of results
     *
     * Return: the results stored in mapped structure
     */
    virtual SLModelResult classify(const MatrixXd& tX, const MatrixXd& tY, SLMODELRESULTYPE type) const;
    
    /* Set Parameters:
     * Input
     *      parameters: Model assignable parameters
     *
     * Return: true if sucessed.
     *
     * Discussion: no optional parameters for Sparse PLS
     */
    bool setParameters(SLSparsePlsParameters& parameters);
    
    /* Get Parameters:
     *
     * Return: current parameters.
     */
    SLSparsePlsParameters getParameters() const { return param; }
    
private:
    SLModelResult getTrainResult(SLMODELRESULTYPE type) const;
    
private:
    // assignable parameters via setParameters() method
    
    // not assignable parameters
    SLSparsePlsParameters param;
    MatrixXd X;
    MatrixXd Y;
    MatrixXd T;
    MatrixXd Beta;
    MatrixXd Res;
    MatrixXd W;
    
    friend class SLPlsColumnSelectionAverage;
    friend class SLPlsColumnSelectionRandom;
    friend class SLPlsColumnSelectionVariance;
    
    friend class SLPlsModeRregession;
    friend class SLPlsModeClassification;
};

#endif
