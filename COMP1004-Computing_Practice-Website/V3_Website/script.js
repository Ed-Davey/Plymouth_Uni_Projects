function openPopupWindow(pageID){
    const popup = document.getElementById('popup');
    popup.style.display = 'flex';

    document.querySelectorAll('.popup-page').forEach((page) => {
        page.classList.remove('active');
    });

    const activePage = document.getElementById(`popup-${pageID}`);
    if (activePage) {
        activePage.classList.add('active');
    }
}

function closePopup() {
    // Hide the popup
    const popup = document.getElementById('popup');
    popup.style.display = 'none';
}

window.onpopstate = function (event) {
    if (event.state && event.state.page) {
        openPopup(event.state.page);
    } else {
        closePopup();
    }
};

function updateTips() {
    var position = document.getElementById("Position").value;
    var tip1 = document.getElementById("tip1");
    var tip2 = document.getElementById("tip2");
    var tip3 = document.getElementById("tip3");

    var firstTip = {
        "GK": "This is for goalkeeper",
        "LB/LWB": "This is for LB/LWB",
        "CB": "This is for CB",
        "RB/RWB": "This is for RB/RWB",
        "CDM": "This is for CDM",
        "CM": "This is for CM",
        "CAM": "This is for CAM",
        "LM/LW": "This is for LM/LW",
        "RM/RW": "This is for RM/RW",
        "ST": "This is for ST"
    };

    var secondTip = {"GK": "This is for goalkeeper",
        "LB/LWB": "This is for LB/LWB",
        "CB": "This is for CB",
        "RB/RWB": "This is for RB/RWB",
        "CDM": "This is for CDM",
        "CM": "This is for CM",
        "CAM": "This is for CAM",
        "LM/LW": "This is for LM/LW",
        "RM/RW": "This is for RM/RW",
        "ST": "This is for ST"
    };

    var thirdTip = {"GK": "This is for goalkeeper",
        "LB/LWB": "This is for LB/LWB",
        "CB": "This is for CB",
        "RB/RWB": "This is for RB/RWB",
        "CDM": "This is for CDM",
        "CM": "This is for CM",
        "CAM": "This is for CAM",
        "LM/LW": "This is for LM/LW",
        "RM/RW": "This is for RM/RW",
        "ST": "This is for ST"
    };

    tip1.textContent = firstTip[position] || "Select a position to get tips.";
    tip2.textContent = secondTip[position] || "Select a position to get tips.";
    tip3.textContent = thirdTip[position] || "Select a position to get tips.";
}

let AllLeagues = {};
let AllStats = {};

// fetch data inside json file
fetch('data.json')
    .then(response => response.json())
    .then(data => {
        AllLeagues = data.Leagues;
        AllStats = data.Stats;
    })
    .catch(error => console.error("Error loading statistics", error))

function fetchData(){
    let SelectedLeague = document.getElementById("League").value;
    let tableBody = document.querySelector("#leagueTable tbody")

    tableBody.innerHTML = ""; //clear data in table

    //Don't show stats if no league selected
    if (SelectedLeague === "--") {
        return;
    }

    //See if league is in the json file
    let leagueStats = AllLeagues.find(league => league.name === SelectedLeague);
    if (!leagueStats) {
        console.error("No leagues found.");
        return;
    }

    let teams = leagueStats.teams;

    teams.forEach(team => {
        let row = tableBody.insertRow();
        row.insertCell(0).textContent = team.position;
        row.insertCell(1).textContent = team.name;
        row.insertCell(2).textContent = team.games_played;
        row.insertCell(3).textContent = team.wins;
        row.insertCell(4).textContent = team.draws;
        row.insertCell(5).textContent = team.loses;
        row.insertCell(6).textContent = team.goal_difference;
        row.insertCell(7).textContent = team.points;
    });
}

function FetchStats() {
    let SelectedLeague = document.getElementById("Stats_League").value;
    let SelectedStat = document.getElementById("Stats").value;
    let tableBody = document.querySelector("#statsTable tbody")

    tableBody.innerHTML = ""; //clear data in table

    //Don't show stats if no league or stat selected
    if (SelectedLeague === "--" || SelectedStat === "--") {
        return;
    }

    //See if league is in the json file
    let leagueStats = AllStats.find(league => league.name === SelectedLeague);
    if (!leagueStats) {
        console.error("No leagues found.");
        return;
    }

    //See if stat is in the json file
    let statData = leagueStats[SelectedStat];

    if (!statData) {
        console.error("No stat found.");
        return;
    }

    statData.forEach(player => {
        let row = tableBody.insertRow();
        row.insertCell(0).textContent = player.name;
        row.insertCell(1).textContent = player.goals || player.assists || player.clean_sheets;
        row.insertCell(2).textContent = player.games;
        row.insertCell(3).textContent = player.goals_per_game || player.assists_per_game || player.clean_sheets_per_game;
    });
}

//add form to table
document.getElementById("statsForm").addEventListener("submit", function (event) {
    event.preventDefault();//prevent submission of the form

    //get the values
    let name = document.getElementById("Player_Name").value;
    let games = document.getElementById("Games_Played").value;
    let goals = document.getElementById("Goals").value;
    let assists = document.getElementById("Assists").value;
    let cleanSheets = document.getElementById("Clean_Sheets").value;
    let yellowCards = document.getElementById("Yellow_Cards").value;
    let redCards = document.getElementById("Red_Cards").value;

    //validate fields have been entered
    if (!name || !games || !goals || !assists || !cleanSheets || !yellowCards || !redCards) {
        alert("Please fill out the whole form before submitting");
        return;
    }

    //add to table
    let table = document.getElementById("StatisticsTable").getElementsByTagName('tbody')[0];
    let newRow = table.insertRow();

    newRow.innerHTML = `
        <td>${name}</td>
        <td>${games}</td>
        <td>${goals}</td>
        <td>${assists}</td>
        <td>${cleanSheets}</td>
        <td>${yellowCards}</td>
        <td>${redCards}</td>
    `;

    //clear form
    document.getElementById("statsForm").reset();
});

//remove all fields from table
document.getElementById("Reset_Stats").addEventListener("click", function () {
    let table = document.getElementById("StatisticsTable").getElementsByTagName('tbody')[0];
    table.innerHTML = "";//remove rows
});

//remove last entry from table
document.getElementById("Remove_Entry").addEventListener("click", function () {
    let table = document.getElementById("StatisticsTable").getElementsByTagName('tbody')[0];
    if (table.rows.length > 0){
        table.deleteRow(table.rows.length - 1);//remove last row
    }
});