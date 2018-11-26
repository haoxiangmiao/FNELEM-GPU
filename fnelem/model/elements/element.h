/**
FNELEM-GPU ELEMENTS
Base structural element class.

@package fnelem.model.elements
@author ppizarror
@date 26/11/2018
@license
	MIT License
	Copyright (c) 2018 Pablo Pizarro R.

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef FNELEM_GPU_ELEMENT_H
#define FNELEM_GPU_ELEMENT_H

// Include headers
#include "../node/node.h"
#include <vector>

class Element : public ModelComponent {
protected:

    // Number of nodes
    int nnodes = 0;

    // Number of degrees of freedom
    int ngdl = 0;

    // Nodes of the element, vector of pointers
    std::vector<Node *> *nodes = new std::vector<Node *>();

    // GDLID of the nodes
    FEMatrix *gdlid;

    // Local stiffness matrix
    FEMatrix *stiffness_local;

    // Global stiffness matrix
    FEMatrix *stiffness_global;

    // Local resistant force
    FEMatrix *force_local;

    // Global resistant force
    FEMatrix *force_global;

    // Element has been initialized
    bool initialized = false;

    // Set gdlid from nodes
    virtual void set_gdlid() {};

    // Add resistant force to reaction
    virtual void add_force_to_reaction() {};

    // Update element after analysis
    virtual void update() {};

    // Save element properties to file
    virtual void save_properties(std::ofstream &file) const {};

    // Save internal stress to file
    virtual void save_internal_stress(std::ofstream &file) const {};

public:

    // Destroy
    ~Element();

    // Constructor
    explicit Element(std::string tag);

    // Get node number
    int get_node_number() const;

    // Get number of degrees of freedom
    int get_ngdl() const;

    // Get element nodes
    std::vector<Node *> *get_nodes() const;

    // Get GDLID associated with the element
    FEMatrix *get_gdlid() const;

    // Get local stiffness matrix
    FEMatrix *get_stiffness_local() const;

    // Get global stiffness matrix
    FEMatrix *get_stiffness_global() const;

    // Get local resistant force
    FEMatrix *get_force_local() const;

    // Get global resistant force
    FEMatrix *get_force_global() const;

    // Initialize element
    virtual void initialize() {};

    // Display element information to console
    void disp() const override;

};

#endif // FNELEM_GPU_ELEMENT_H