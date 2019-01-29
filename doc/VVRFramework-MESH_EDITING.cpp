///////////////////////////////////////////////////////////////////////////////
// Acquire references to all needed objects ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    // ATTENTION:
    //      When acquiring vertrex and triangle references,
    //      DONT FORGET: The `&` otherwise you'll get a copy of the vectors
    //                   and not the mesh's actual vectors.
    //

    vvr::Mesh                   &mesh  = a_mesh_object;
    std::vector<Vec3d>          &verts = mesh.getVertices();
    std::vector<vvr::Triangle>  &tris  = mesh.getTriangles(); // >>> DONT FORGET &

    // We either use an existing mesh OR ...
    // we could just declare a new (empty) one like this:

    Mesh mesh;

///////////////////////////////////////////////////////////////////////////////
// Add new triangles to existing mesh /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    // Push new vertices
    // It's important to specify them in CW order.
    // This means that their CW normal will look towards their front face.

    verts.push_back(Vec3d(10,10,10));
    verts.push_back(Vec3d(20,10,10));
    verts.push_back(Vec3d(10,20,10));

    // `vi` : Index of first triangle vertex inside vertex vector.
    // The 3 indices are these: { Last,  Last - 1,  Last - 2}

    unsigned vi = verts.size()-3;

    // Push the new triangle.
    // An existing vertex could also be used, instead of the 3 new ones.
    // In that case, we would use its index inside the vertex vector.

    tris.push_back(vvr::Triangle(&verts, vi, vi+1, vi+2));

///////////////////////////////////////////////////////////////////////////////
// Erase triangles from mesh //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

    unsigned index_to_erase;
    tris.erase(tris.begin() + index_to_erase);


