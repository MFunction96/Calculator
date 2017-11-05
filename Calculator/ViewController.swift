//
//  ViewController.swift
//  Calculator
//
//  Created by MFunction on 2017/10/24.
//  Copyright © 2017年 MFunction. All rights reserved.
//

import UIKit
import Foundation

class ViewController: UIViewController {

    @IBOutlet weak var BtnPi: UIButton!
    @IBOutlet weak var BtnE: UIButton!
    @IBOutlet weak var BtnClear: UIButton!
    @IBOutlet weak var BtnLBracket: UIButton!
    @IBOutlet weak var BtnRBracket: UIButton!
    @IBOutlet weak var BtnBackspace: UIButton!
    @IBOutlet weak var BtnMClear: UIButton!
    @IBOutlet weak var Btn7: UIButton!
    @IBOutlet weak var Btn8: UIButton!
    @IBOutlet weak var Btn9: UIButton!
    @IBOutlet weak var BtnDivide: UIButton!
    @IBOutlet weak var BtnMRecord: UIButton!
    @IBOutlet weak var Btn4: UIButton!
    @IBOutlet weak var Btn5: UIButton!
    @IBOutlet weak var Btn6: UIButton!
    @IBOutlet weak var BtnMinus: UIButton!
    @IBOutlet weak var BtnMultiple: UIButton!
    @IBOutlet weak var BtnMPlus: UIButton!
    @IBOutlet weak var Btn1: UIButton!
    @IBOutlet weak var Btn2: UIButton!
    @IBOutlet weak var Btn3: UIButton!
    @IBOutlet weak var BtnPlus: UIButton!
    @IBOutlet weak var BtnEqual: UIButton!
    @IBOutlet weak var BtnMMinus: UIButton!
    @IBOutlet weak var Btn0: UIButton!
    @IBOutlet weak var BtnDot: UIButton!
    @IBOutlet weak var BtnNegative: UIButton!
    @IBOutlet weak var TfFormula: UITextField!
    @IBOutlet weak var TfResult: UITextField!
    @IBOutlet weak var TfMemory: UITextField!
    
    var sh = shell()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    @IBAction func AcPi(_ sender: Any) {
        
    }
    @IBAction func AcE(_ sender: Any) {
        
    }
    @IBAction func AcClear(_ sender: Any) {
        sh.clear()
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcLBracket(_ sender: Any) {
        do
        {
            try sh.push_operator(4)
        }
        catch
        {
            
        }
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcRBracket(_ sender: Any) {
        do
        {
            try sh.push_operator(5)
        }
        catch
        {
            
        }
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcBackspace(_ sender: Any) {
        sh.backspace()
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcMClear(_ sender: Any) {
        sh.m_clear()
        TfMemory.text = ""
    }
    @IBAction func Ac7(_ sender: Any) {
        sh.push_num("7")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func Ac8(_ sender: Any) {
        sh.push_num("8")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func Ac9(_ sender: Any) {
        sh.push_num("9")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcDivide(_ sender: Any) {
        do
        {
            try sh.push_operator(3)
        }
        catch
        {
        
        }
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcMRecord(_ sender: Any) {
        TfResult.text = sh.m_record()
    }
    @IBAction func Ac4(_ sender: Any) {
        sh.push_num("4")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func Ac5(_ sender: Any) {
        sh.push_num("5")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func Ac6(_ sender: Any) {
        sh.push_num("6")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcMinus(_ sender: Any) {
        do
        {
            try sh.push_operator(1)
        }
        catch
        {
            
        }
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcMultiple(_ sender: Any) {
        do
        {
            try sh.push_operator(2)
        }
        catch
        {
            
        }
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcMPlus(_ sender: Any) {
        sh.m_add(TfResult.text)
        TfMemory.text = sh.m_record() == "0" ? "" : "M"
    }
    @IBAction func Ac1(_ sender: Any) {
        sh.push_num("1")
        TfFormula.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func Ac2(_ sender: Any) {
        sh.push_num("2")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func Ac3(_ sender: Any) {
        sh.push_num("3")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcPlus(_ sender: Any) {
        do
        {
            try sh.push_operator(0)
        }
        catch
        {
            
        }
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcEqual(_ sender: Any) {
    }
    @IBAction func AcMMinus(_ sender: Any) {
        sh.m_minus(TfResult.text)
        TfMemory.text = sh.m_record() == "0" ? "" : "M"
    }
    @IBAction func Ac0(_ sender: Any) {
        sh.push_num("0")
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcDot(_ sender: Any) {
        sh.push_dot()
        TfResult.text = sh.get_buffer()
        TfFormula.text = sh.get_formula()
    }
    @IBAction func AcNegative(_ sender: Any) {
    }
    
}

