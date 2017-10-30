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
    core_cpp wrapped;
}
@end

@implementation Core

- (void)PushNum:(double)num
{
    wrapped.push_num(num);
}

- (void)PushOperator:(NSString*_Nonnull)operation
{
    std::string cpp_str([operation UTF8String], [operation lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    wrapped.push_operator(cpp_str);
}

- (double)Calculate
{
    return wrapped.calculate();
}

- (void)Clear
{
    wrapped.clear();
}

@end
