// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   app.js                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/02/26 14:38:07 by svelhinh          #+#    #+#             //
//   Updated: 2016/02/26 16:48:02 by svelhinh         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

var myApp = angular.module("myApp", []);

myApp.controller("exemple1Ctrl", function($scope){
	$scope.age = 0;
	$scope.majeurOrMineurText = function(){
		return ($scope.age >= 18) ? "majeur" : "mineur";
	};
});

myApp.controller("myController", function($scope){
	$scope.showContent = true;
});

myApp.controller("helloWorld", function($scope){
	$scope.name = "World";
});

myApp.controller("menuCtrl", function($scope){
	$scope.expanders = [
		{
			title: 'Titre 1',
			text: 'Contenu 1'
		},
		{
			title: 'Titre 2',
			text: 'Contenu 2'
		},
		{
			title: 'Titre 3',
			text: 'Contenu 3'
		}
	];
});

myApp.directive("accordion", function(){
	return {
		restrict: 'EA',
		replace: true,
		transclude: true,
		template: "<div ng-transclude></div>",
		controller: function(){
			var expanders = [];
			this.gotOpened = function(selectedExpander){
				expanders.forEach(function(expander){
					if (selectedExpander != expander){
						expander.showMe = false;
					}
				});
			};
			this.addExpander = function(expander){
				expanders.push(expander);
			};
		}
	};
});

myApp.directive("expander", function(){
	return {
		restrict: 'EA',
		replace: true,
		transclude: true,
		require: '^?accordion',
		scope: {title: '=expanderTitle'},
		template: '<div>' +
		'<div class="title" ng-click="toggle()">{{title}}</div>' +
		'<div class="body" ng-show="showMe" ng-transclude></div>' +
		'</div>',
		link: function(scope, element, attrs, accordionController){
			scope.showMe = false;
			accordionController.addExpander(scope);
			scope.toggle = function toggle(){
				scope.showMe = !scope.showMe;
				accordionController.gotOpened(scope);
			};
		}
	};
});
