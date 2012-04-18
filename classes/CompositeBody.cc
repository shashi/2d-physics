#include "classes/CompositeBody.h"

#include <algorithm>

#include "classes/Anchor.h"
#include "classes/Point.h"

CompositeBody::CompositeBody() {}

Point CompositeBody::centroid() {
    int i = 0, len = parts.size();
    Point centroid, part_centroid;
    float sum_x = 0.0, sum_y = 0.0, part_weight;

    for (i = 0; i < len; i++) {
        part_centroid = parts[i].centroid();
        part_weight   = parts[i].weight();
        
        sum_x += part_centroid.x * part_weight;
        sum_y += part_centroid.y * part_weight;
    }

    centroid = Point(sum_x / len, sum_y / len);

    return centroid;
}

float CompositeBody::weight() {
    int i = 0, len = parts.size();
    float weight;

    for (i = 0; i < len; i++) {
        weight   = parts[i].weight();
    }

    return weight;
}

void CompositeBody::draw() {
    int i = 0, len = parts.size();

    for (i = 0; i < len; i++) {
        parts[i].draw();
    }
}

float CompositeBody::moment(Point about) {
    return 0.0;
}

void CompositeBody::ApplyTransform(Transform trans) {
    Transform temp;
    Point _centroid = centroid();
    int i = 0, len = parts.size();

    for (i = 0; i < len; i++) {
        temp.addTranslate(_centroid.x, _centroid.y);
        // parts[i].ApplyTransform(temp);
    }
}
