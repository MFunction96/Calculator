//
//  Shell.swift
//  Calculator
//
//  Created by MFunction on 2017/10/26.
//  Copyright © 2017年 MFunction. All rights reserved.
//

import Foundation
import UIKit
import MachO

class Shell {
    
    var buffer = Buffer()
    var core = Core()
    let PI = acos(-1.0)
    var formula = UITextField()
    //var formula : UITextField
    /*init(textField : UITextField) {
        formula = textField
    }*/
    
    func SetTextField(textField : UITextField) {
        formula = textField
    }
    
    func Clear() {
        buffer.Clear()
        formula.text = "0"
    }
}
