//
//  SecondViewController.swift
//  d05
//
//  Created by Sergio VELHINHO on 6/19/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Locations.locs.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "locCell") as! LocationTableViewCell
        
        cell.loc = Locations.locs[indexPath.row]
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        FirstViewController.indexLoc = indexPath.row
        tabBarController?.selectedIndex = 0
    }

}

