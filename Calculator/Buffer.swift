//
//  Buffer.swift
//  Calculator
//
//  Created by MFunction on 2017/10/25.
//  Copyright © 2017年 MFunction. All rights reserved.
//

import Foundation

public class Buffer {
    
    private var _data = 0.0
    
    public func Add(x : Double) {
        _data += x
    }
    public func Minus(x : Double) {
        _data -= x
    }
    public func Clear() {
        _data = 0.0
    }
    public func Record() -> Double {
        return _data
    }
}
