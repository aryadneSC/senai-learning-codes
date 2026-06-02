package com.example.cadastraproduto;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private ArrayList<String> produtos;
    private ArrayAdapter<String> adapter;
    private ListView listView;
    private static final int REQUEST_CODE_CADASTRO = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        produtos = new ArrayList<>();
        adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, produtos);

        listView = findViewById(R.id.listViewProdutos);
        listView.setAdapter(adapter);

        FloatingActionButton fab = findViewById(R.id.fabAdicionar);
        fab.setOnClickListener(v -> {
            Intent intent = new Intent(MainActivity.this, CadastroProdutoActivity.class);
            startActivityForResult(intent, REQUEST_CODE_CADASTRO);
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_CODE_CADASTRO && resultCode == RESULT_OK && data != null) {
            String nome = data.getStringExtra("nome");
            String preco = data.getStringExtra("preco");
            String item = nome + " - R$" + preco;
            produtos.add(item);
            adapter.notifyDataSetChanged();
        }
    }
}