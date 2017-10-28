//
//  AddPersonViewController.swift
//  d02
//
//  Created by Sergio VELHINHO on 6/14/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class AddPersonViewController: UIViewController {

    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var datePicker: UIDatePicker!
    @IBOutlet weak var descriptionTextView: UITextView!

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "doneSegue"
        {
            if let vc = segue.destination as? ViewController
            {
                if nameField?.text?.isEmpty == false && descriptionTextView.text!.isEmpty == false
                {
                    Data.people.insert((nameField.text!, descriptionTextView.text!, datePicker.date.description), at: 0)
                    vc.tableView.reloadData()
                }
            }
        }
    }
    
    @IBAction func doneButton()
    {
        performSegue(withIdentifier: "doneSegue", sender: self)
    }

}
