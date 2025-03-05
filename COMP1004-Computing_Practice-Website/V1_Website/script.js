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