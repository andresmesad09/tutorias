
/*
1) ¿Cuántos reportes que contenían un concepto con prioridad “Urgente” envió cada
gerencia?
*/
SELECT g.nombre                     AS nombre_gerencia
     , COUNT(DISTINCT r.id_reporte) AS total_reportes
FROM reporte r
         LEFT JOIN gerencia g
                   ON r.id_gerencia = g.id_gerencia
         LEFT JOIN reporte_concepto rc
                   ON rc.id_reporte = r.id_reporte
         LEFT JOIN concepto c
                   ON c.id_concepto = rc.id_concepto
WHERE  1 = 1
AND c.prioridad = 'Urgente'
GROUP BY g.nombre;

/*
2) ¿Quién es el gerente (nombre + apellido) de la gerencia que suma el mayor número de
correcciones totales?
*/
SELECT CONCAT(e.nombre, ' ', e.apellido) AS gerente
     , SUM(rc.correcciones)              AS total_correcciones
FROM reporte r
         LEFT JOIN gerencia g
                   ON r.id_gerencia = g.id_gerencia
         LEFT JOIN reporte_concepto rc
                   ON rc.id_reporte = r.id_reporte
         LEFT JOIN empleado e
                   ON e.id_empleado = g.id_gerente
GROUP BY CONCAT(e.nombre, ' ', e.apellido)
ORDER BY SUM(rc.correcciones) DESC
LIMIT 1;

/*
Dé un listado de cada empleado con su respectivo jefe.
*/
SELECT e1.id_empleado
     , CONCAT(e1.nombre, ' ', e1.apellido)                                                               AS nombre_empleado
     , e1.id_jefe
     , CASE WHEN e1.id_jefe IS NULL THEN 'Es la VPF' ELSE CONCAT(e2.nombre, ' ', e2.apellido) END AS nombre_jefe
FROM empleado e1
         LEFT JOIN empleado e2
                   ON e1.id_jefe = e2.id_empleado;