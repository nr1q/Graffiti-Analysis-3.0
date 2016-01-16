/*
 *  polyAdv.h
 *  ensanche_2.0
 *
 *  Created by Chris on 1/15/10.
 *  Copyright 2010 csugrue. All rights reserved.
 *
 */

#pragma once

#include "polySimple.h"
#include "polyUtils.h"


class polyAdv : public polySimple
{
public:
    polyAdv();
    ~polyAdv();
    polyAdv (const polyAdv & mom);

    virtual void createFromRect (ofRectangle rect);
    virtual bool bHitTest (float x, float y);
};
