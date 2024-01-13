from fastapi import FastAPI, HTTPException
import subprocess
from fastapi.middleware.cors import CORSMiddleware

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["GET"],
    allow_headers=["*"],
)

@app.get("/ejecutar_programa")
def ejecutar_programa(codigo: str):
    try:
        # Obtener el código del usuario desde la URL
        codigo_usuario = codigo
        # Convertir el código C a una cadena de Python
        codigo_python = f'''{codigo_usuario}'''

        # Guardar el código en un archivo
        with open('C:/Users/paule/OneDrive/Documentos/UniTareas/7Sem/SS/flex-bison-image/compilator.txt', 'w') as archivo:
            archivo.write(codigo_usuario)

        # Comando para ejecutar el contenedor Docker
        comando_docker = f'docker run --rm -v C:/Users/paule/OneDrive/Documentos/UniTareas/7Sem/SS:/app flex-bison-image'

        # Ejecutar el comando
        resultado = subprocess.run(comando_docker, shell=True, capture_output=True, text=True)

        # Verificar si hubo un error en la ejecución
        if resultado.returncode != 0:
            raise HTTPException(status_code=500, detail=f"Error en la ejecución del contenedor: {resultado.stderr}")

        # Devolver la salida como JSON
        return {'resultado': resultado.stdout.strip()}
    except Exception as e:
        # Manejar errores
        raise HTTPException(status_code=500, detail=str(e))

if __name__ == '__main__':
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
