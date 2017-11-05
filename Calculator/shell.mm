//
//  shell.m
//  Calculator
//
//  Created by MFunction on 2017/10/31.
//  Copyright © 2017年 MFunction. All rights reserved.
//

#import "shell.h"
#import "shellcpp.hpp"

@interface shell () {
    shell_cpp wrapped;
}
@end


@implementation shell

- (void)backspace
{
    wrapped.backspace();
}

- (void)clear
{
    wrapped.clear();
}

- (void)m_add:(NSString*)num
{
    std::string cpp_str([num UTF8String], [num lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    wrapped.m_add(cpp_str);
}

- (void)m_minus:(NSString*)num
{
    std::string cpp_str([num UTF8String], [num lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    wrapped.m_minus(cpp_str);
}

- (void)m_clear
{
    wrapped.m_clear();
}

- (void)push_num:(NSString*)num
{
    std::string cpp_str([num UTF8String], [num lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    try
    {
        wrapped.push_num(cpp_str);
    }
    catch (exception e)
    {
        throw exception();
    }
    
}

- (void)push_operator:(int)index
{
    try
    {
        wrapped.push_operator(index);
    }
    catch (exception e)
    {
        throw exception();
    }
}

- (void)push_dot
{
    wrapped.push_dot();
}

- (double)get_num
{
    return wrapped.get_num();
}

- (double)calculate
{
    try
    {
        return wrapped.calculate();
    }
    catch (exception e)
    {
        throw exception();
    }
}

- (NSString*)m_record
{
    std::string str = std::string(wrapped.m_record());
    NSString *nsstr= [NSString stringWithCString:str.c_str() encoding:[NSString defaultCStringEncoding]];
    return nsstr;
}

- (NSString*)get_buffer
{
    std::string str = std::string(wrapped.get_buffer());
    NSString *nsstr= [NSString stringWithCString:str.c_str() encoding:[NSString defaultCStringEncoding]];
    return nsstr;
}

- (NSString*)get_formula
{
    std::string str = std::string(wrapped.get_formula());
    NSString *nsstr= [NSString stringWithCString:str.c_str() encoding:[NSString defaultCStringEncoding]];
    return nsstr;
}

@end
