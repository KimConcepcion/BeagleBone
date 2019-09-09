var ctx_temp = document.getElementById('temp_chart');
var ctx_hum = document.getElementById('hum_chart');
ctx_temp.style.backgroundColor = '#FFFFFF';
ctx_hum.style.backgroundColor = '#FFFFFF';

//  Temperature code:
let temp_chart = new Chart(ctx_temp, {
  type: 'line',
  data: {
    labels: [1,2,3,4,5,6,7,8,9,10],
    datasets: [
      {
        label: "Temperature",
        data: [15,19,13,16,11,12,13,13,15,16],
        borderColor: "#c45850",
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
          labelString: "Time [hr]"
        }
      }],
      yAxes: [{
        scaleLabel: {
          display: true,
          labelString: "Temperature [°C]"
        }
      }]
    }
  }
})

//  Humidity code:
let hum_chart = new Chart(ctx_hum, {
  type: 'line',
  data: {
    labels: [1,2,3,4,5,6,7,8,9,10],
    datasets: [
      {
        label: "Humidity",
        data: [5,9,3,6,1,2,3,13,5,6],
        borderColor: "#3371FF",
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
          labelString: "Time [hr]"
        }
      }],
      yAxes: [{
        scaleLabel: {
          display: true,
          labelString: "Humidity [%]"
        }
      }]
    }
  }
})
