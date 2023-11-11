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

# Crear el gráfico 3D de la superficie
fig_3d = go.Figure(data=[go.Surface(x=X, y=Y, z=Z, colorscale=[[0, 'green'], [1, 'green']], showscale=False)])

# Configuración del modo oscuro para el gráfico 3D
fig_3d.update_layout(
    title='Gráfico en 3D de la Ecuación Definida por el Usuario',
    title_font_color='green',
    paper_bgcolor='black',  # Fondo alrededor del gráfico
    scene=dict(
        xaxis=dict(color='green', gridcolor="darkgreen", backgroundcolor='black'),
        yaxis=dict(color='green', gridcolor="darkgreen", backgroundcolor='black'),
        zaxis=dict(color='green', gridcolor="darkgreen", backgroundcolor='black'),
        bgcolor='black',  # Fondo de la escena 3D
        xaxis_title='X',
        yaxis_title='Y',
        zaxis_title='Z',
        xaxis_title_font_color='green',
        yaxis_title_font_color='green',
        zaxis_title_font_color='green',
    ),
    autosize=True
)

# Mostrar el gráfico 3D
fig_3d.show()

# Crear el gráfico de contorno 2D (el código no se modifica)
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
    xaxis=dict(showgrid=True, gridwidth=1, gridcolor='darkgreen', zerolinecolor='green', linecolor='green', zerolinewidth=2),
    yaxis=dict(showgrid=True, gridwidth=1, gridcolor='darkgreen', zerolinecolor='green', linecolor='green', zerolinewidth=2),
    xaxis_title='X',
    yaxis_title='Y',
    xaxis_title_font_color='green',
    yaxis_title_font_color='green',
    autosize=True
)

# Mostrar el gráfico 2D
fig_2d.show()
