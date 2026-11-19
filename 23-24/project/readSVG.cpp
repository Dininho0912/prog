#include <iostream>
#include "SVGElements.hpp"
#include "external/tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

namespace svg {
    void readSVG(const string& svg_file, Point& dimensions, vector<SVGElement*>& svg_elements) {
        XMLDocument doc; // Cria um objeto XMLDocument para carregar e manipular o arquivo SVG.

        XMLError r = doc.LoadFile(svg_file.c_str()); // Carrega o arquivo SVG e armazena o resultado em 'r'.

        if (r != XML_SUCCESS) {
            throw runtime_error("Unable to load " + svg_file); // Lança uma exceção se o carregamento falhar.
        }

        XMLElement* xml_elem = doc.RootElement(); // Obtém o elemento raiz do documento XML.

        dimensions.x = xml_elem->IntAttribute("width"); // Lê o atributo 'width' do elemento raiz.
        dimensions.y = xml_elem->IntAttribute("height"); // Lê o atributo 'height' do elemento raiz.
        
        // Obtém o primeiro elemento filho do elemento raiz.
        XMLElement* child = xml_elem->FirstChildElement();
        
        // Itera sobre todos os elementos filhos do elemento raiz.
        while (child) {
            const char* name = child->Value();
            
            if (strcmp(name, "circle") == 0) {
                Color fill = svg::parse_color(child->Attribute("fill"));
                Point center{child->IntAttribute("cx"), child->IntAttribute("cy")};
                Point radius{child->IntAttribute("r"), child->IntAttribute("r")};
                svg_elements.push_back(new Circle(fill, center, radius));
            } 
            else if (strcmp(name, "ellipse") == 0) {
                Color fill = svg::parse_color(child->Attribute("fill"));
                Point center{child->IntAttribute("cx"), child->IntAttribute("cy")};
                Point radius{child->IntAttribute("rx"), child->IntAttribute("ry")};
                svg_elements.push_back(new Ellipse(fill, center, radius)); 
            } 
            else if (strcmp(name, "polyline") == 0) {
                Color fill = svg::parse_color(child->Attribute("stroke"));
                const char* points_str = child->Attribute("points");
                
                vector<Point> points;
                char* str = strdup(points_str);
                char* keyw = strtok(str, " ");
                while (keyw != NULL) {
                    char* coordenada = strtok(keyw, ",");
                    int x = atoi(coordenada);
                    coordenada = strtok(NULL, ",");
                    int y = atoi(coordenada);
                    points.push_back(Point{x, y});
                    keyw = strtok(NULL, " ");
                }
                free(str);
                svg_elements.push_back(new Polyline(points, fill));
            }
            else if (strcmp(name, "line") == 0) {
                Color fill = svg::parse_color(child->Attribute("stroke"));
                Point start{child->IntAttribute("x1"), child->IntAttribute("y1")};
                Point end{child->IntAttribute("x2"), child->IntAttribute("y2")};
                svg_elements.push_back(new Line(fill, start, end));
            }
            else if (strcmp(name, "polygon") == 0) {
                Color fill = svg::parse_color(child->Attribute("fill"));
                const char* points_str = child->Attribute("points");
                
                vector<Point> points;
                char* str = strdup(points_str);
                char* keyw = strtok(str, " ");
                while (keyw != NULL) {
                    char* coordenada = strtok(keyw, ",");
                    int x = atoi(coordenada);
                    coordenada = strtok(NULL, ",");
                    int y = atoi(coordenada);
                    points.push_back(Point{x, y});
                    keyw = strtok(NULL, " ");
                }
                free(str);
                svg_elements.push_back(new Polygon(points, fill));
            }
            else if (strcmp(name, "rect") == 0) {
                Color fill = svg::parse_color(child->Attribute("fill"));
                int x = child->IntAttribute("x");
                int y = child->IntAttribute("y");
                int width = child->IntAttribute("width");
                int height = child->IntAttribute("height");
                svg_elements.push_back(new Rect(fill, Point{x, y}, width, height));
            }
            child = child->NextSiblingElement();
        }
    }
}