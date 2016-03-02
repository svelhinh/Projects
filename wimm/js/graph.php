<script>
var ctx = document.getElementById("myChart").getContext("2d");
var data = [
    {
        value: '<?php echo $argent; ?>',
        color:"#F7464A",
        highlight: "#FF5A5E",
		label: '<?php echo $type_compte; ?>'
    },
    {
        value: '<?php echo $argent2; ?>',
        color: "#46BFBD",
        highlight: "#5AD3D1",
		label: '<?php echo $type_compte2; ?>'
    },
    {
        value: '<?php echo $argent3; ?>',
        color: "#FDB45C",
        highlight: "#FFC870",
		label: '<?php echo $type_compte3; ?>'
    }
];
new Chart(ctx).PolarArea(data, {
    segmentStrokeColor: "#000000"
});

canvas.onclick = function(evt){
    var activePoints = myPolarAreaChart.getSegmentsAtEvent(evt);
    // => activePoints is an array of segments on the canvas that are at the same position as the click event.
};
</script>
