package com.example.cadastroprodutos;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class activity_cadastro_produto extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_cadastro_produto);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }

    public void cadastrarProduto(View v) {
        EditText edtNomeProduto = findViewById(R.id.edtNomePdt);
        String nomePdt = edtNomeProduto.getText().toString();

        EditText edtPrecoProduto = findViewById(R.id.edtPrecoPdt);
        String valorInserido = edtPrecoProduto.getText().toString();
        double precoPdt = Double.parseDouble(valorInserido);

        Intent intent = getIntent();
        String nome = getIntent().getStringExtra("nomeProduto");

        double preco = getIntent().getDoubleExtra("precoProduto");

        TextView msg = findViewById(R.id.txtCadastrado);
        msg.setText("Produto casastrado com sucesso!");
    }

    public void voltar(View v) {
        Intent i = new Intent(getApplicationContext(), MainActivity.class);
    }

    // Recebe botão inicial
    // cod



}