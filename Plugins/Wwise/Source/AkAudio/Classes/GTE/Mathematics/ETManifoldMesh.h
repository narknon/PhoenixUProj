// David Eberly, Geometric Tools, Redmond WA 98052
// Copyright (c) 1998-2020
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
// https://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// Version: 4.0.2019.08.13

#pragma once

#include <Mathematics/Logger.h>
#include <Mathematics/EdgeKey.h>
#include <Mathematics/TriangleKey.h>
#include <map>
#include <memory>
#include <vector>

namespace gte
{
    class ETManifoldMesh
    {
    public:
        // Edge data types.
        class Edge;
        typedef std::shared_ptr<Edge>(*ECreator)(int, int);
        typedef std::map<EdgeKey<false>, std::shared_ptr<Edge>> EMap;

        // Triangle data types.
        class Triangle;
        typedef std::shared_ptr<Triangle>(*TCreator)(int, int, int);
        typedef std::map<TriangleKey<true>, std::shared_ptr<Triangle>> TMap;

        // Edge object.
        class Edge
        {
        public:
            virtual ~Edge() = default;

            Edge(int v0, int v1)
                :
                V{ v0, v1 }
            {
            }

            // Vertices of the edge.
            std::array<int, 2> V;

            // Triangles sharing the edge.
            std::array<std::weak_ptr<Triangle>, 2> T;
        };

        // Triangle object.
        class Triangle
        {
        public:
            virtual ~Triangle() = default;

            Triangle(int v0, int v1, int v2)
                :
                V{ v0, v1, v2 }
            {
            }

            // Vertices, listed in counterclockwise order (V[0],V[1],V[2]).
            int V[3];

            // Adjacent edges.  E[i] points to edge (V[i],V[(i+1)%3]).
            std::array<std::weak_ptr<Edge>, 3> E;

            // Adjacent triangles.  T[i] points to the adjacent triangle
            // sharing edge E[i].
            std::array<std::weak_ptr<Triangle>, 3> T;
        };


        // Construction and destruction.
        virtual ~ETManifoldMesh() = default;

        ETManifoldMesh(ECreator eCreator = nullptr, TCreator tCreator = nullptr)
            :
            mECreator(eCreator ? eCreator : CreateEdge),
            mTCreator(tCreator ? tCreator : CreateTriangle),
            mThrowOnNonmanifoldInsertion(true)
        {
        }

        // Support for a deep copy of the mesh.  The mEMap and mTMap objects
        // have dynamically allocated memory for edges and triangles.  A
        // shallow copy of the pointers to this memory is problematic.
        // Allowing sharing, say, via std::shared_ptr, is an option but not
        // really the intent of copying the mesh graph.
        ETManifoldMesh(ETManifoldMesh const& mesh)
        {
            *this = mesh;
        }

        ETManifoldMesh& operator=(ETManifoldMesh const& mesh)
        {
            Clear();

            mECreator = mesh.mECreator;
            mTCreator = mesh.mTCreator;
            mThrowOnNonmanifoldInsertion = mesh.mThrowOnNonmanifoldInsertion;
            for (auto const& element : mesh.mTMap)
            {
                Insert(element.first.V[0], element.first.V[1], element.first.V[2]);
            }

            return *this;
        }

        // Member access.
        inline EMap const& GetEdges() const
        {
            return mEMap;
        }

        inline TMap const& GetTriangles() const
        {
            return mTMap;
        }

        // If the insertion of a triangle fails because the mesh would become
        // nonmanifold, the default behavior is to throw an exception.  You
        // can disable this behavior and continue gracefully without an
        // exception.  The return value is the previous value of the internal
        // state mAssertOnNonmanifoldInsertion.
        bool ThrowOnNonmanifoldInsertion(bool doException)
        {
            std::swap(doException, mThrowOnNonmanifoldInsertion);
            return doException;  // return the previous state
        }

        // If <v0,v1,v2> is not in the mesh, a Triangle object is created and
        // returned; otherwise, <v0,v1,v2> is in the mesh and nullptr is
        // returned.  If the insertion leads to a nonmanifold mesh, the call
        // fails with a nullptr returned.
        virtual std::shared_ptr<Triangle> Insert(int v0, int v1, int v2)
        {
            TriangleKey<true> tkey(v0, v1, v2);
            if (mTMap.find(tkey) != mTMap.end())
            {
                // The triangle already exists.  Return a null pointer as a
                // signal to the caller that the insertion failed.
                return nullptr;
            }

            // Create the new triangle.  It will be added to mTMap at the end
            // of the function so that if an assertion is triggered and the
            // function returns early, the (bad) triangle will not be part of
            // the mesh.
            std::shared_ptr<Triangle> tri = mTCreator(v0, v1, v2);

            // Add the edges to the mesh if they do not already exist.
            for (int i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
            {
                EdgeKey<false> ekey(tri->V[i0], tri->V[i1]);
                std::shared_ptr<Edge> edge;
                auto eiter = mEMap.find(ekey);
                if (eiter == mEMap.end())
                {
                    // This is the first time the edge is encountered.
                    edge = mECreator(tri->V[i0], tri->V[i1]);
                    mEMap[ekey] = edge;

                    // Update the edge and triangle.
                    edge->T[0] = tri;
                    tri->E[i0] = edge;
                }
                else
                {
                    // This is the second time the edge is encountered.
                    edge = eiter->second;
                    LogAssert(edge != nullptr, "Unexpected condition.");

                    // Update the edge.
                    if (edge->T[1].lock())
                    {
                        if (mThrowOnNonmanifoldInsertion)
                        {
                            LogError("Attempt to create nonmanifold mesh.");
                        }
                        else
                        {
                            return nullptr;
                        }
                    }
                    edge->T[1] = tri;

                    // Update the adjacent triangles.
                    auto adjacent = edge->T[0].lock();
                    LogAssert(adjacent != nullptr, "Unexpected condition.");
                    for (int j = 0; j < 3; ++j)
                    {
                        if (adjacent->E[j].lock() == edge)
                        {
                            adjacent->T[j] = tri;
                            break;
                        }
                    }

                    // Update the triangle.
                    tri->E[i0] = edge;
                    tri->T[i0] = adjacent;
                }
            }

            mTMap[tkey] = tri;
            return tri;
        }

        // If <v0,v1,v2> is in the mesh, it is removed and 'true' is
        // returned; otherwise, <v0,v1,v2> is not in the mesh and 'false' is
        // returned.
        virtual bool Remove(int v0, int v1, int v2)
        {
            TriangleKey<true> tkey(v0, v1, v2);
            auto titer = mTMap.find(tkey);
            if (titer == mTMap.end())
            {
                // The triangle does not exist.
                return false;
            }

            // Get the triangle.
            std::shared_ptr<Triangle> tri = titer->second;

            // Remove the edges and update adjacent triangles if necessary.
            for (int i = 0; i < 3; ++i)
            {
                // Inform the edges the triangle is being deleted.
                auto edge = tri->E[i].lock();
                LogAssert(edge != nullptr, "Unexpected condition.");

                if (edge->T[0].lock() == tri)
                {
                    // One-triangle edges always have pointer at index zero.
                    edge->T[0] = edge->T[1];
                    edge->T[1].reset();
                }
                else if (edge->T[1].lock() == tri)
                {
                    edge->T[1].reset();
                }
                else
                {
                    LogError("Unexpected condition.");
                }

                // Remove the edge if you have the last reference to it.
                if (!edge->T[0].lock() && !edge->T[1].lock())
                {
                    EdgeKey<false> ekey(edge->V[0], edge->V[1]);
                    mEMap.erase(ekey);
                }

                // Inform adjacent triangles the triangle is being deleted.
                auto adjacent = tri->T[i].lock();
                if (adjacent)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (adjacent->T[j].lock() == tri)
                        {
                            adjacent->T[j].reset();
                            break;
                        }
                    }
                }
            }

            mTMap.erase(tkey);
            return true;
        }

        // Destroy the edges and triangles to obtain an empty mesh.
        virtual void Clear()
        {
            mEMap.clear();
            mTMap.clear();
        }

        // A manifold mesh is closed if each edge is shared twice.  A closed
        // mesh is not necessarily oriented.  For example, you could have a
        // mesh with spherical topology.  The upper hemisphere has outer
        // facing normals and the lower hemisphere has inner-facing normals.
        // The discontinuity in orientation occurs on the circle shared by the
        // hemispheres.
        bool IsClosed() const
        {
            for (auto const& element : mEMap)
            {
                auto edge = element.second;
                if (!edge->T[0].lock() || !edge->T[1].lock())
                {
                    return false;
                }
            }
            return true;
        }

        // Test whether all triangles in the mesh are oriented consistently
        // and that no two triangles are coincident.  The latter means that
        // you cannot have both triangles <v0,v1,v2> and <v0,v2,v1> in the
        // mesh to be considered oriented.
        bool IsOriented() const
        {
            for (auto const& element : mEMap)
            {
                auto edge = element.second;
                if (edge->T[0].lock() && edge->T[1].lock())
                {
                    // In each triangle, find the ordered edge that
                    // corresponds to the unordered edge element.first.  Also
                    // find the vertex opposite that edge.
                    bool edgePositive[2] = { false, false };
                    int vOpposite[2] = { -1, -1 };
                    for (int j = 0; j < 2; ++j)
                    {
                        auto tri = edge->T[j].lock();
                        for (int i = 0; i < 3; ++i)
                        {
                            if (tri->V[i] == element.first.V[0])
                            {
                                int vNext = tri->V[(i + 1) % 3];
                                if (vNext == element.first.V[1])
                                {
                                    edgePositive[j] = true;
                                    vOpposite[j] = tri->V[(i + 2) % 3];
                                }
                                else
                                {
                                    edgePositive[j] = false;
                                    vOpposite[j] = vNext;
                                }
                                break;
                            }
                        }
                    }

                    // To be oriented consistently, the edges must have
                    // reversed ordering and the oppositive vertices cannot
                    // match.
                    if (edgePositive[0] == edgePositive[1] || vOpposite[0] == vOpposite[1])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        // Compute the connected components of the edge-triangle graph that
        // the mesh represents.  The first function returns pointers into
        // 'this' object's containers, so you must consume the components
        // before clearing or destroying 'this'.  The second function returns
        // triangle keys, which requires three times as much storage as the
        // pointers but allows you to clear or destroy 'this' before consuming
        // the components.
        void GetComponents(std::vector<std::vector<std::shared_ptr<Triangle>>>& components) const
        {
            // visited: 0 (unvisited), 1 (discovered), 2 (finished)
            std::map<std::shared_ptr<Triangle>, int> visited;
            for (auto const& element : mTMap)
            {
                visited.insert(std::make_pair(element.second, 0));
            }

            for (auto& element : mTMap)
            {
                auto tri = element.second;
                if (visited[tri] == 0)
                {
                    std::vector<std::shared_ptr<Triangle>> component;
                    DepthFirstSearch(tri, visited, component);
                    components.push_back(component);
                }
            }
        }

        void GetComponents(std::vector<std::vector<TriangleKey<true>>>& components) const
        {
            // visited: 0 (unvisited), 1 (discovered), 2 (finished)
            std::map<std::shared_ptr<Triangle>, int> visited;
            for (auto const& element : mTMap)
            {
                visited.insert(std::make_pair(element.second, 0));
            }

            for (auto& element : mTMap)
            {
                std::shared_ptr<Triangle> tri = element.second;
                if (visited[tri] == 0)
                {
                    std::vector<std::shared_ptr<Triangle>> component;
                    DepthFirstSearch(tri, visited, component);

                    std::vector<TriangleKey<true>> keyComponent;
                    keyComponent.reserve(component.size());
                    for (auto const& t : component)
                    {
                        keyComponent.push_back(TriangleKey<true>(t->V[0], t->V[1], t->V[2]));
                    }
                    components.push_back(keyComponent);
                }
            }
        }

    protected:
        // The edge data and default edge creation.
        static std::shared_ptr<Edge> CreateEdge(int v0, int v1)
        {
            return std::make_shared<Edge>(v0, v1);
        }

        ECreator mECreator;
        EMap mEMap;

        // The triangle data and default triangle creation.
        static std::shared_ptr<Triangle> CreateTriangle(int v0, int v1, int v2)
        {
            return std::make_shared<Triangle>(v0, v1, v2);
        }

        TCreator mTCreator;
        TMap mTMap;
        bool mThrowOnNonmanifoldInsertion;  // default: true

        // Support for computing connected components.  This is a
        // straightforward depth-first search of the graph but uses a
        // preallocated stack rather than a recursive function that could
        // possibly overflow the call stack.
        void DepthFirstSearch(std::shared_ptr<Triangle> const& tInitial,
            std::map<std::shared_ptr<Triangle>, int>& visited,
            std::vector<std::shared_ptr<Triangle>>& component) const
        {
            // Allocate the maximum-size stack that can occur in the
            // depth-first search.  The stack is empty when the index top
            // is -1.
            std::vector<std::shared_ptr<Triangle>> tStack(mTMap.size());
            int top = -1;
            tStack[++top] = tInitial;
            while (top >= 0)
            {
                std::shared_ptr<Triangle> tri = tStack[top];
                visited[tri] = 1;
                int i;
                for (i = 0; i < 3; ++i)
                {
                    std::shared_ptr<Triangle> adj = tri->T[i].lock();
                    if (adj && visited[adj] == 0)
                    {
                        tStack[++top] = adj;
                        break;
                    }
                }
                if (i == 3)
                {
                    visited[tri] = 2;
                    component.push_back(tri);
                    --top;
                }
            }
        }
    };
}
