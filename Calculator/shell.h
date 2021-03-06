//
//  shell.h
//  Calculator
//
//  Created by MFunction on 2017/10/31.
//  Copyright © 2017年 MFunction. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface shell : NSObject

- (void)backspace;
- (void)clear;
- (void)m_add:(NSString*)num;
- (void)m_minus:(NSString*)num;
- (void)m_clear;
- (void)push_num:(NSString*)num;
- (void)push_operator:(int)index;
- (void)push_dot;
- (void)push_const:(NSString*)c;
- (void)negative;
- (void)set_buffer:(NSString*)num;
- (bool)check;
- (NSString*)calculate;
- (NSString*)m_record;
- (NSString*)get_buffer;
- (NSString*)get_formula;

@end
