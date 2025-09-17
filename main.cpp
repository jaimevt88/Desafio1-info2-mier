#include <iostream>
#include <fstream>

int main() {
    const int NUM_SEMANAS = 3;
    const int NUM_DIAS = 8;
    const int MAX_NOMBRE_DIA = 11;

    int ventas_semanales[NUM_SEMANAS][NUM_DIAS] = {
        {1, 150, 200, 180, 220, 300, 450, 250},
        {2, 160, 210, 195, 230, 320, 480, 260},
        {3, 170, 225, 205, 245, 340, 500, 280}
    };

    char encabezados[NUM_DIAS][MAX_NOMBRE_DIA] = {
        "Semana", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"
    };
    std::cout << encabezados;

    const char* nombre_archivo = "ventas.csv";

    std::ofstream archivo_csv(nombre_archivo);

    if (!archivo_csv.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
        return 1;
    }

    for (int i = 0; i < NUM_DIAS; ++i) {
        archivo_csv << encabezados[i];
        if (i < NUM_DIAS - 1) {
            archivo_csv << ",";
        }
    }
    archivo_csv << "\n";

    for (int i = 0; i < NUM_SEMANAS; ++i) {
        for (int j = 0; j < NUM_DIAS; ++j) {
            archivo_csv << ventas_semanales[i][j];
            if (j < NUM_DIAS - 1) {
                archivo_csv << ",";
            }
        }
        archivo_csv << "\n";
    }

    archivo_csv.close();

    std::cout << "Los datos se han guardado en '" << nombre_archivo << "' exitosamente." << std::endl;



    return 0;
}
//ESto es un comentario
//Esto es otro comentario
