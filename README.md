# Programación II – Segundo Obligatorio 2025

Licenciatura en Informática / Ingeniería en Informática  
Total: **100 puntos** – **Mínimo de aprobación: 50 puntos**

> Este material es de uso exclusivo para los cursos impartidos por Universidad de la Empresa. :contentReference[oaicite:0]{index=0}

---

## 1. Indicaciones generales

- Los grupos deberán tener **exactamente tres (3) integrantes**.
- En caso de que la cantidad total de estudiantes de la clase **no sea múltiplo de 3**, se admitirá **excepcionalmente** algún grupo de **dos (2) integrantes**.
- El trabajo obligatorio consistirá en la **resolución del problema** presentado en este enunciado.

### 1.1. Fecha y forma de entrega

- **Fecha de entrega**: **Lunes 1 de diciembre de 2025**.
- Se debe enviar un **mail al docente** especificando:
  - Nombres y cédulas de todos los integrantes del grupo.
  - Adjuntar un archivo llamado **`Obligatorio2.zip`** que contenga:

#### Contenido de `Obligatorio2.zip`

1. **Carpeta con el proyecto de Code::Blocks**, incluyendo todos los archivos:
   - Archivos de cabecera: `.h`
   - Archivos de implementación: `.cpp`
2. **No** deben incluirse:
   - Archivos compilados `.o` de la subcarpeta `obj`
   - Archivo ejecutable `.exe` de la subcarpeta `bin`
3. **Diagrama de módulos**:
   - Archivo en formato **JPG o PDF** con:
     - Diagrama de módulos implementados.
     - Inclusiones correspondientes.
   - El diagrama debe coincidir con los módulos efectivamente entregados.

### 1.2. Trabajo en clase y defensa oral

- Se destinará **una semana y media del curso** para trabajar en el obligatorio durante el horario de clase, con el docente disponible para orientar y responder dudas.
- Aun así, se espera que los grupos dediquen **tiempo extra** fuera del horario de clase para completar el trabajo.

#### Defensa oral

- En la última clase previa a la entrega:
  - **Montevideo y Punta del Este**: viernes 28/11  
  - **Colonia**: sábado 29/11
- Se realizará una **defensa oral del obligatorio** a cada grupo.
- La defensa consistirá en **preguntas sobre el trabajo**, tanto de:
  - **Diseño**
  - **Implementación**
- **Todos los integrantes** del grupo deben participar.
- El desempeño en la defensa influirá en la **nota final** del trabajo.

---

## 2. Objetivo

Aplicar diversos conocimientos vistos a lo largo del curso y practicar el trabajo en grupo mediante la resolución del problema planteado. :contentReference[oaicite:1]{index=1}

---

## 3. Planteo del problema

Se trata de una **pequeña academia de barrio** que imparte **talleres de cocina** sobre diversas temáticas (pastas, pastelería, etc.) y que necesita un programa para:

- Registrar la información de los **alumnos** que asisten.
- Registrar los datos de los **talleres** que realizan en la academia.

### 3.1. Alumnos

- La cantidad de alumnos es **relativamente elevada**, sin cota máxima.
- Cada alumno está identificado por su **cédula**.
- Se debe registrar:
  - Cédula
  - Nombre
  - Apellido
  - Fecha de nacimiento
  - Dirección
  - Teléfono
- Los datos de los alumnos deben almacenarse en memoria **ordenados por cédula**.

### 3.2. Registros de finalización de talleres

Cada vez que un alumno completa un taller se ingresa un **registro de finalización** con:

- Nombre del taller
- Fecha de finalización
- Cédula del alumno
- Cantidad de días que le tomó completarlo

Características:

- Los registros de finalización deben mantenerse **ordenados cronológicamente**.
- Cada nuevo registro tendrá una **fecha igual o posterior** a la del último registro ingresado.
- No hay **cota máxima** para la cantidad de registros.
- Puede haber:
  - Alumnos sin ningún registro (no han completado su primer taller).
  - Alumnos con varios registros (han realizado varios talleres).
  - Varios registros con la **misma fecha**.

---

## 4. Requerimientos del sistema

Los requerimientos se dividen en **Altas y bajas**, **Listados**, **Consultas** y **Persistencia en archivos**. :contentReference[oaicite:2]{index=2}

### 4.1. Altas y bajas

1. **Alta de alumno**
   - Ingresar los datos de un nuevo alumno.
   - Validar previamente:
     - Que el alumno **no exista** ya en el sistema.
     - Que la **fecha de nacimiento** sea **válida**.

2. **Alta de registro de finalización**
   - Ingresar un nuevo registro de finalización de taller.
   - Validar previamente:
     - Que el **alumno exista** en el sistema.
     - Que la **fecha** sea válida.
     - Que la fecha sea **mayor o igual** a la del **último registro ingresado**.

3. **Baja de alumno**
   - Dada la **cédula** de un alumno, borrarlo del sistema.
   - Validar previamente:
     - Que la cédula exista en el sistema.
   - Además de borrar al alumno, se deben borrar **todos sus registros de finalización**.

---

### 4.2. Listados

1. **Listado de todos los alumnos**
   - Listar todos los alumnos registrados, **ordenados por cédula** de menor a mayor.
   - En una misma línea deben aparecer:
     - Cédula, nombre, apellido, fecha de nacimiento, dirección y teléfono.

2. **Listado de alumnos sin talleres completados**
   - Listar todos los alumnos que **no han completado ningún taller**.
   - Ordenados por cédula de menor a mayor.
   - Mismos datos en una línea: cédula, nombre, apellido, fecha de nacimiento, dirección, teléfono.

3. **Listado de registros por alumno**
   - Dada la **cédula** de un alumno:
     - Listar todos sus registros de finalización.
     - Ordenados cronológicamente de los **más antiguos a los más recientes**.
   - En una misma línea:
     - Nombre del taller, fecha de finalización, cédula del alumno, cantidad de días.
   - Validar que el alumno exista.

4. **Listado de registros posteriores a una fecha**
   - Dada una **fecha**, listar todos los registros de finalización **posteriores** a dicha fecha.
   - Ordenados cronológicamente de los más antiguos a los más recientes.
   - En una misma línea:
     - Nombre del taller, fecha de finalización, cédula del alumno, cantidad de días.

---

### 4.3. Consultas

1. **Cantidad de alumnos por fecha de nacimiento**
   - Dada una **fecha de nacimiento**, contar cuántos alumnos nacieron en esa fecha.
   - Validar previamente que la fecha sea **válida**.

2. **Comparación de apellidos**
   - Dado un **apellido**, contar cuántos alumnos:
     - Tienen un apellido **alfabéticamente menor**.
     - Tienen un apellido **alfabéticamente mayor**.
     - Tienen **exactamente** ese apellido.

3. **Cantidad de registros en una fecha**
   - Dada una **fecha**, contar cuántos registros de finalización fueron ingresados en esa fecha.
   - Validar previamente que sea una fecha válida.

4. **Taller más popular**
   - Obtener el **nombre del taller más popular** (el que fue realizado por la mayor cantidad de alumnos).
   - Devolver también la cantidad de registros de finalización correspondiente.
   - En caso de empate, alcanza con devolver **uno cualquiera**.

5. **Alumno de mayor edad**
   - Obtener:
     - Cédula
     - Nombre
     - Apellido
     - Fecha de nacimiento
   - del alumno con la **mayor edad** (fecha de nacimiento más antigua).
   - En caso de empate, alcanza con devolver **uno cualquiera**.

---

## 5. Persistencia de datos en archivos

Los datos deben permanecer respaldados en disco cuando el programa no esté en ejecución. :contentReference[oaicite:3]{index=3}

Se utilizarán dos archivos de texto:

- **`Alumnos.txt`**  
  Para respaldar los datos de los alumnos.

- **`Registros.txt`**  
  Para respaldar los datos de los registros de finalización de talleres.

### 5.1. Reglas de uso

- Ambos archivos se **crean automáticamente** la **primera vez** que se ejecuta el programa.
- Cada vez que el programa **inicia**:
  - Debe **recuperar los datos** de los archivos y cargarlos en memoria.
- Cada vez que el programa **finaliza**:
  - Debe **respaldar nuevamente** los datos en los archivos.
- Durante la ejecución se trabaja **exclusivamente con los datos en memoria**.

> Observación: se supone que todos los datos caben en memoria mientras el programa está en ejecución. En un sistema real podría no ser así, pero esas estrategias escapan al alcance del curso.

---

## 6. Trabajo solicitado

Se pide:

### a) Definición de estructuras de datos

Pensar cuáles son las **estructuras de datos más adecuadas** para representar:

- Los **alumnos**.
- Los **registros de finalización de talleres**.
- Cualquier estructura auxiliar que el diseño requiera.

Escribir en C++ **todos los tipos de datos correspondientes**.

---

### b) Diagrama de módulos

A partir de los tipos de datos definidos:

- Dibujar el **diagrama de módulos** del sistema.
- Definir cuidadosamente las **inclusiones** entre módulos.

---

### c) Archivos `.h` de los módulos

Escribir en C++ los archivos `.h` correspondientes a cada módulo, incluyendo:

- Definición del **tipo** correspondiente.
- **Cabezal** de las operaciones del módulo.

Para cada operación:

- Decidir si debe ser **función** o **procedimiento**.
- Detallar **toda precondición necesaria**.
- Analizar cada requerimiento del enunciado y definir los **cabezales de todas las operaciones** necesarias para resolverlo.

---

### d) Implementación de los módulos (`.cpp`)

Implementar en C++ los archivos `.cpp` correspondientes a los módulos definidos.

Recomendaciones:

- Hacer un **programa de prueba por módulo** antes de pasar al siguiente.
- **No** intentar probar el programa completo todo de una vez.
- Probar cada módulo por separado ayuda a detectar errores a tiempo.

---

### e) Programa principal (`main`)

Implementar en C++ el programa principal que:

- Invoque a las operaciones de los módulos anteriores.
- Dé solución a **todos los requerimientos** del enunciado.
- Haga uso de **tres menús de opciones**:
  1. Menú para **altas y bajas**.
  2. Menú para **listados**.
  3. Menú para **consultas**.

Se debe definir un **módulo adicional de menús**, que también debe estar incluido en el diagrama de módulos de la parte (b).

> Observación: se debe decidir en qué módulo corresponde colocar cada operación del sistema. Al implementar cada una, utilizar operaciones auxiliares de otros módulos cuando sea necesario, para lograr una correcta distribución del trabajo entre módulos.

---
