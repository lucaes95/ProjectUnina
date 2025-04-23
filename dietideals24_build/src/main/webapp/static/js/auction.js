// Funzione per ottenere la data e ora attuali +1 ora
function getCurrentDateTimePlusOneHour() {
  let now = new Date();
  now.setHours(now.getHours() + 1);

  let year = now.getFullYear();
  let month = String(now.getMonth() + 1).padStart(2, "0");
  let day = String(now.getDate()).padStart(2, "0");
  let hours = String(now.getHours()).padStart(2, "0");
  let minutes = String(now.getMinutes()).padStart(2, "0");

  return `${year}-${month}-${day}T${hours}:${minutes}`;
}

function getCurrentLimitDate() {
  let now = new Date();
  now.setHours(now.getHours() + 1);
  now.setMinutes(now.getMinutes() + 10);

  let year = now.getFullYear();
  let month = String(now.getMonth() + 1).padStart(2, "0");
  let day = String(now.getDate()).padStart(2, "0");
  let hours = String(now.getHours()).padStart(2, "0");
  let minutes = String(now.getMinutes()).padStart(2, "0");

  return `${year}-${month}-${day}T${hours}:${minutes}`;
}

document.addEventListener("DOMContentLoaded", function () {
  let minDateTime = getCurrentDateTimePlusOneHour();

  let endTimeField = document.getElementById("endTime");
  endTimeField.min = minDateTime;
  endTimeField.value = getCurrentLimitDate();
  document
    .getElementById("auctionForm")
    .addEventListener("submit", function (event) {
      let selectedDate = document.getElementById("endTime").value;
      let currentDate = getCurrentDateTimePlusOneHour();

      if (selectedDate < currentDate) {
        event.preventDefault();
        alert("L'asta deve terminare almeno un'ora dopo l'inizio.");
      }
    });
});
