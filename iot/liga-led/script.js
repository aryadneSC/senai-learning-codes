/*Importar firebase*/
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.8.0/firebase-app.js";
import { getDatabase, ref, set, onValue } from "https://www.gstatic.com/firebasejs/10.8.0/firebase-database.js";

/*Config firebase*/
const firebaseConfig = {
  apiKey: "AIzaSyAPi-HXO7ZFhItHS4KiEB-Dgrob-wk1BCc",
  authDomain: "senai-led-id.firebaseapp.com",
  databaseURL: "https://senai-led-id-default-rtdb.firebaseio.com",
  projectId: "senai-led-id",
  storageBucket: "senai-led-id.firebasestorage.app",
  messagingSenderId: "766377806899",
  appId: "1:766377806899:web:a716d1a9bfe2fba873a746"
};

/* Initialize firebase*/
const app = initializeApp(firebaseConfig);

const db = getDatabase(app);
const estadoRef = ref(db, "iot/LED/estado"); // conector status led

/* controle led*/
const led = document.getElementById('led');
const statusTxt = document.getElementById('status');
const btn = document.getElementById('btn');

let ligado = false;

function alternarTexto() {
    if (document.getElementById('btn').textContent === 'Ligar LED') {
        document.getElementById('btn').textContent = 'Desligar LED';
        document.getElementById('status').textContent = 'LIGADO';
        set(estadoRef, true);
    } else {
        document.getElementById('btn').textContent = 'Ligar LED';
        document.getElementById('status').textContent = 'DESLIGADO';
        set(estadoRef, false);
    }
}

window.alternarTexto = alternarTexto;