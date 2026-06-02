package com.example.cadastraproduto;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private static final int REQUEST_CODE_CADASTRO = 1;
    private ArrayList<Produto> listaProdutos;
    private ArrayAdapter<Produto> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listaProdutos = new ArrayList<>();

        ListView listView = findViewById(R.id.listViewProdutos);
        Button btnAdicionar = findViewById(R.id.btnAdd);

        adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, listaProdutos);
        listView.setAdapter(adapter);

        btnAdicionar.setOnClickListener(view -> {
            Intent intent = new Intent(MainActivity.this, CadastroProdutoActivity.class);
            startActivityForResult(intent, REQUEST_CODE_CADASTRO);
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_CODE_CADASTRO && resultCode == RESULT_OK && data != null) {
            String nome = data.getStringExtra("nome");
            double preco = data.getDoubleExtra("preco", 0.0);

            Produto novoProduto = new Produto(nome, preco);
            listaProdutos.add(novoProduto);
            adapter.notifyDataSetChanged();
        }
    }
}