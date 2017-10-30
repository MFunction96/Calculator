//
//  Core.h
//  Calculator
//
//  Created by MFunction on 2017/10/26.
//  Copyright © 2017年 MFunction. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Core : NSObject

- (void)PushNum : (double)num;
- (void)PushOperator : (NSString*_Nonnull)operation;
- (double)Calculate;
- (void)Clear;

@end
