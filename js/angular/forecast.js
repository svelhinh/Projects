app.factory('forecast', ['$http', function($http)
{
	return $http.get('http://wimm.esy.es/fichier.json')
	.success(function(data)
	{
		console.log("yo");
		return data;
	})
	.error(function(err)
	{
		console.log("pas yo");
		return err;
	});
}]);
