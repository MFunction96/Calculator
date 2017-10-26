//
//  Core.mm
//  Calculator
//
//  Created by MFunction on 2017/10/26.
//  Copyright © 2017年 MFunction. All rights reserved.
//


#include "Core.h"
#include "CoreCpp.hpp"

@interface Core () {
@private
    CoreCpp * __obj;
}
@end

@implementation Core

- (instancetype)init
{
    self = [super init];
    if (self) {
        __obj = new CoreCpp();
    }
    return self;
}

- (void)dealloc
{
    delete __obj;
    __obj = NULL;
}

@end
