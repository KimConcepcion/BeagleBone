var ctx = document.getElementById('cpu_chart');
ctx.style.backgroundColor = '#FFFFFF';

let cpu_chart = new Chart(ctx, {
  type: 'line',
  data: {
    labels: [1500,1600,1700,1750,1800,1850,1900,1950,1999,2050],
    datasets: [
      {
        label: "CPU Performance",
        data: [86,114,106,106,107,111,133,221,783,2478],
        borderColor: "#3cba9f",
        fill: false
      }
    ]
  },
  options: {
    responsive: false,
    maintainAspectRatio: false,
    scales: {
      xAxes: [{
        scaleLabel: {
          display: true,
          labelString: "Time [s]"
        }
      }]
    }
  }
})
