//
//  SLGlp.h
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

#ifndef __GLP__SLGlp__
#define __GLP__SLGlp__

// Factories
#include "Factory/SLGlpFactory.h"

// Models
#include "Models/SLModel.h"
#include "Models/SLSparsePls.h"
#include "Models/SLNipals.h"

// Graph Mining
#include "GraphMining/SLGspan.h"

// Extensions
#include "Extensions/MatrixExt.h"

// Utilities
#include "SLUtility.h"
#include "Utilities/SLCrossValidation.h"
#include "Models/SLModelUtility.h"
#include "Utilities/SLResultHistory.h"

#endif
