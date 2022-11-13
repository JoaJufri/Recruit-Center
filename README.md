# Recruit-Center
Proyecto de Sistema de gestión de Archivos con POO para Laboratorio de Computacion II
------
![image](https://user-images.githubusercontent.com/96314580/201542363-26ec004f-9870-4315-b4e2-d7f2a6b579e7.png)

Proyecto de gestión: RECRUIT CENTER
Alumno :
Jufrida Joaquin, Legajo: 26917
“ Recruit Center ” es una aplicación para una Empresa de reclutamiento de talentos IT, la cual lleva
el mismo nombre y donde Programadores que estén buscando empleo suben sus CV, y estos
quedan almacenados en los archivos de la aplicación, para futuras consultas.
Está destinada exclusivamente a Recruiters.
Su objetivo es facilitar el acceso a las búsquedas de talentos que piden los distintos Clientes, así
mismo como permitirle al Recruiter agilizar la búsqueda de un candidato adecuado para cada
búsqueda, mediante un sistema de “Filtros de Búsqueda”. Los cual permiten reducir
notoriamente la lista de “Candidatos que sean mas adecuados para el puesto buscado”.
Permitiendo así, partir de una lista de (por ejemplo), 200 candidatos de los cuales se dispone,
aplicar los filtros que coincidan con los requisitos para el puesto enviado por el Cliente, quedarse
con 10 candidatos, por ejemplo, que serían los que mas coincidencias tienen en lo que a requisitos
para el puesto se refiere. Y de esos 10 poder elegir los que desee para enviarle al Cliente, para que
el mismo pueda programar entrevistas.

El sistema ya posee una “Base de datos” (Archivos), donde tiene los datos de:

Los Recruiters (id,password,nombre,apellido)
Los Candidatos (Los datos del mismo y sus CVS, se verá más en detalle en el UML).
Los Clientes que solicitan búsquedas.
Las Búsquedas solicitadas por los Clientes y los requisitos solicitados para las mismas. Las
mismas están ya asignadas a un Recruiter. Es decir, cada recruiter puede tener mas de una
búsqueda asignada, pero una misma búsqueda no puede estar asignada a varios
recruiters.
El sistema se mueve entre diversas pantallas de menú, con sus respectivas opciones.
El primero de estos es el menú principal donde tiene la opción de Logearse o salir del programa.

Si el Recruiter no se logea, no puede acceder al resto de funcionalidades.
Luego de logearse el Recruiter podrá ver solamente las Búsquedas que su usuario tenga
asignadas.
Deberá seleccionar de esta lista una Búsqueda para activarla.

De lo contrario solo tendrá acceso a las búsquedas finalizadas por él (si es que tiene), en la sección
“BUSQUEDAS FINALIZADAS”.

Si el recruiter no tiene una búsqueda activa, no podrá entrar al resto de funcionalidades en
“Selección de personal”.

Luego de activar una Búsqueda, el Recruiter no podrá cambiar la búsqueda mientras
permanezca logeado, hasta que la búsqueda finalice , es decir, hasta que tenga candidatos
seleccionados por el recruiter, y pase de activa a inactiva. Pero si el recruiter sale al menú de login
principal, pierde su condición de logeado y debe volver a ingresar sus credenciales y de esta forma
puede seleccionar cualquier búsqueda para activar. (Una búsqueda que fue activada y se dejó sin
finalizar, no sufre ninguna alteración en la misma o el sistema de archivos).

Teniendo una Búsqueda activa, el recruiter podrá acceder a la selección de Candidatos y sus
diversas opciones.
Aquí podrá observar la lista de Candidatos en su totalidad, ver el archivo de “Favoritos” (si es que
tiene registros), el cual es un archivo donde se cargan los candidatos filtrados hasta el momento
para la búsqueda activa.
También podrá ingresar a la sección de “Envió de Candidatos”, en la cual se podrá seleccionar
Candidatos del archivo de Favoritos, para mandárselos al cliente, y elegir si concluir la búsqueda o
seguir cargando candidatos para la búsqueda activa. De no haber Registros en el archivo de
Favoritos en el momento, no podrá elegir un candidato para ser Enviado en esta sección.

Cuando se terminan de enviar los candidatos seleccionados para la busqueda activa, ésta cambia
su estado a concluida y ya no aparecerá como búsqueda disponible (Se actualiza el estado en el
archivo de búsquedas). El recruiter puede activar otra búsqueda que tenga asignada, si es que
tiene, y así sucesivamente hasta quedarse sin búsquedas, es decir sin tareas. O puede optar por
salir cuando lo desee.

Los requisitos deseados de las búsqueda se basan en : años de experiencia (redondea para abajo,
es decir si trabajó 2 años y 3 meses, sólo toma 3 años), nivel de inglés ( desde A-1 a C1-C2 ),
Salario Ofrecido para el puesto, si acepta o no trabajo remoto, el Seniority buscado, y los
lenguajes/frameworks preferidos para el puesto (El Stack ), los cuales cada candidato puede cargar
hasta un máximo de 10.

Mediante distintos filtros, el recruiter podrá seleccionar los candidatos que sean más adecuados
para la búsqueda, es decir los que tengan más coincidencias con los filtros aplicados.
Los filtros son :

✓ Filtro por salario pretendido
✓ Filtro por lenguaje/framework (stack)
✓ Filtro por años de experiencia
✓ Filtro por Cercanía/Ubicación, es decir los candidatos que estén dentro de la provincia
donde esté el cliente que solicita la búsqueda (esto puede ser útil cuando la búsqueda no
acepta trabajo remoto)
✓ Filtro por Nivel de Inglés
✓ Filtro por Seniority actual del candidato
Estos filtros se aplican sobre los datos de los candidatos, y las coincidencias se guardan en un
archivo “Favoritos”, los filtros son acumulativos, es decir, si por ejemplo hay 200 Candidatos
totales, y luego de aplicar un filtro hay 100 coincidentes, el archivo de “Favoritos” pasa a tener
esos 100 candidatos, y si elegimos otro filtro, ahora va a filtrar sobre esos 100 favoritos, y no sobre
los 200 candidatos. A menos que seleccionemos la opción “ Borrar filtros” que vacía el archivo de
Favoritos.

Se utilizó composición de clases, herencia, constructores, memoria dinámica, archivos, etc.

Se está utilizando la biblioteca “Rlutil” , para mejorar el aspecto visual de la interfaz, aunque se
centro en la funcionalidad del proyecto y dejamos para lo último la parte visual, así que los menus
por ahora como no están modelados con rlutil, son “borradores” para ejemplo de este informe.

Ejemplo de archivo final de “Elegidos” (Opción “Búsquedas finalizadas” del Menú de Búsqueda:

Ejemplo de Candidato :

Notas:

Cuando el archivo de favoritos está vacío, al acceder a la opción de “Filtros”, automáticamente el
archivo de Favoritos se carga con todos los Candidatos del archivo de Candidatos.
Ya que los filtros, siempre actúan sobre el Archivo de Favoritos, y no sobre la de Candidatos que
nunca se modifica.

Registros del archivo “Recruiters.dat” (Necesario para logearse):

Registro del Archivo “Empresas.dat”, donde están cargados los clientes que solicitan las
búsquedas:
