app.controller('controller', ['$scope', function($scope) { 
	$scope.title = 'Yo YO yo';
	$scope.products = [
	{
		name: 'Sergio',
		price: 10000000000000,
		date: new Date('2016', '02', '25'),
		cover: 'https://cdn.intra.42.fr/userprofil/svelhinh.jpg',
		likes: 0,
		dislikes: 0
	},
	{
		name: 'Samuel',
		price: 0,
		date: new Date('2016', '02', '24'),
		cover: 'https://cdn.intra.42.fr/userprofil/stoussay.jpg',
		likes: 0,
		dislikes: 0
	},
	{
		name: 'Vetea',
		price: 10,
		date: new Date('2016', '02', '23'),
		cover: 'https://cdn.intra.42.fr/userprofil/vtata.jpg',
		likes: 0,
		dislikes: 0
	}
	];
	$scope.plusOne = function(index)
	{
		$scope.products[index].likes += 1;
	};
	$scope.minusOne = function(index)
	{
		$scope.products[index].dislikes += 1;
	};
	$scope.sergio = {
		icon: $scope.products[0].cover,
		title: 'Sergio',
		price: 0.99
  };

  $scope.samuel = {
	icon: $scope.products[1].cover,
    title: 'Samuel',
    price: 2.99
  };

  $scope.vetea = {
	icon: $scope.products[2].cover,
    title: 'Vetea',
    price: 1.99
  };
}]);
