import plotly.graph_objects as go
import numpy as np

# Definir los rangos de X e Y
x_range = np.linspace(-5, 5, 100)
y_range = np.linspace(-5, 5, 100)

# Crear una malla de coordenadas para X e Y
X, Y = np.meshgrid(x_range, y_range)

# Definir la ecuación de la superficie
ecuacion = "(X**2)/9 + (Y**2)/4 - 1"

# Evaluar la ecuación para obtener los valores de Z
Z = eval(ecuacion)

# Crear el gráfico de contorno 2D
fig_2d = go.Figure(data=[
    go.Contour(
        x=x_range, 
        y=y_range, 
        z=Z, 
        colorscale=[[0, 'green'], [1, 'green']],
        autocontour=False,
        contours=dict(
            start=0, 
            end=0, 
            size=0.1,
            coloring='lines',
        ),
        line_width=2
    )
])

# Configuración del modo oscuro para el gráfico 2D
fig_2d.update_layout(
    title='Gráfico de Contorno en 2D de la Ecuación',
    title_font_color='green',
    paper_bgcolor='black',
    plot_bgcolor='black',
    xaxis=dict(
        showgrid=True, 
        gridwidth=1, 
        gridcolor='darkgreen', 
        zerolinecolor='green', 
        linecolor='green', 
        zerolinewidth=2, 
        tickmode='auto', 
        nticks=10, 
        ticks='outside', 
        tickcolor='green', 
        showticklabels=True
    ),
    yaxis=dict(
        showgrid=True, 
        gridwidth=1, 
        gridcolor='darkgreen', 
        zerolinecolor='green', 
        linecolor='green', 
        zerolinewidth=2, 
        tickmode='auto', 
        nticks=10, 
        ticks='outside', 
        tickcolor='green', 
        showticklabels=True
    ),
    xaxis_title='X',
    yaxis_title='Y',
    xaxis_title_font_color='green',
    yaxis_title_font_color='green',
    autosize=True,
    annotations=[
        go.layout.Annotation(
            x=0,
            y=1,
            xref="paper",
            yref="paper",
            text=r"$\large \frac{X^2}{9} + \frac{Y^2}{4} = 1$",
            showarrow=False,
            font=dict(
                family="Courier New, monospace",
                size=80,  # Tamaño de fuente más grande
                color="white"
            ),
            align="left",
            bgcolor="black",
            bordercolor="green",
            borderwidth=2
        )
    ]
)

# Agregar anotaciones para puntos importantes
fig_2d.add_trace(go.Scatter(x=[0], y=[0], text=["Centro"], mode='text', textposition="bottom center", textfont=dict(color='white', size=16)))
fig_2d.add_trace(go.Scatter(x=[3, -3, 0, 0], y=[0, 0, 2, -2], text=["A", "B", "C", "D"], mode='text+markers', textposition="bottom center", marker=dict(color='red', size=10), textfont=dict(color='white', size=16)))

# Mostrar el gráfico 2D
fig_2d.show()
