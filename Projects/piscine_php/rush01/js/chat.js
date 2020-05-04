$('#envoi').click(function(e){
    e.preventDefault();
    var message = encodeURIComponent( $('#message').val() );

    if(message != "")
    {
        $.ajax({
            url : "traitement.php",
            type : "POST",
            data : "message=" + message
        });
    }
    eraseText();
});


function charger(){

    setTimeout( function()
    {

        var premierID = $('#messages p:last').attr('id');

        $.ajax({
            url : "charger.php?id=" + premierID,
            type : "GET",
            success : function(html){
                $('#messages').append(html);
            }
        });
        charger();
    }, 100);

}

function eraseText() { document.getElementById("message").value = ""; }

$("iframe").scrollTop(300);

charger();

