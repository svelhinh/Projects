$('#up').click(function(e){
    e.preventDefault(); // on empêche le bouton d'envoyer le formulaire

    var up = encodeURIComponent( $('#up').val() ); // on sécurise les données
console.log(up);

    if(up){ // on vérifie que les variables ne sont pas vides
        $.ajax({
            url : "php/game.php", // on donne l'URL du fichier de traitement
            type : "POST", // la requête est de type POST
            data : "direction=" + up // et on envoie nos données
        });
    }
});

$('#down').click(function(e){
    e.preventDefault(); // on empêche le bouton d'envoyer le formulaire

    var down = encodeURIComponent( $('#down').val() );
console.log(down);

    if(down){ // on vérifie que les variables ne sont pas vides
        $.ajax({
            url : "php/game.php", // on donne l'URL du fichier de traitement
            type : "POST", // la requête est de type POST
            data : "direction=" + down // et on envoie nos données
        });
    }
});

$('#left').click(function(e){
    e.preventDefault(); // on empêche le bouton d'envoyer le formulaire

    var left = encodeURIComponent( $('#left').val() );
console.log(left);
    if (left)
    {
           $.ajax({
            url : "php/game.php", // on donne l'URL du fichier de traitement
            type : "POST", // la requête est de type POST
            data : "direction=" + left // et on envoie nos données
        });
    }
});

$('#right').click(function(e){
    e.preventDefault(); // on empêche le bouton d'envoyer le formulaire

    var right = encodeURIComponent( $('#right').val() );
console.log(right);
    if (right)
    {
           $.ajax({
            url : "php/game.php", // on donne l'URL du fichier de traitement
            type : "POST", // la requête est de type POST
            data : "direction=" + right // et on envoie nos données
        });
    }
});

$('#shoot').click(function(e){
    e.preventDefault(); // on empêche le bouton d'envoyer le formulaire

    var shoot = encodeURIComponent( $('#shoot').val() );
console.log(shoot);
    if (shoot)
    {
           $.ajax({
            url : "php/game.php", // on donne l'URL du fichier de traitement
            type : "POST", // la requête est de type POST
            data : "shoot=" + shoot // et on envoie nos données
        });
    }
});

function getUrlVars() {
    var vars = {};
    var parts = window.location.href.replace(/[?&]+([^=&]+)=([^&]*)/gi, function(m,key,value) {
        vars[key] = value;
    });
    return vars;
}

function charger(){

    setTimeout( function(){

        var id = getUrlVars()["id"];
        $.ajax({
            url : "php/reload.php?id=" + id,
            type : "GET",
            success : function(map){
                $('#load_map').replaceWith(map);
            }
        });

        charger();

    });

}

charger();