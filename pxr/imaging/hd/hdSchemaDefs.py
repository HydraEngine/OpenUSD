#
# Copyright 2023 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
[
    dict(
        SCHEMA_NAME = 'ALL_SCHEMAS',
        LIBRARY_PATH = 'pxr/imaging/hd'
    ),

    #--------------------------------------------------------------------------
    # dependency
    dict(
        SCHEMA_NAME = 'Dependency',
        MEMBERS = [
            ('dependedOnPrimPath', T_PATH, {}),
            ('dependedOnDataSourceLocator', T_LOCATOR, {}),
            ('affectedDataSourceLocator', T_LOCATOR, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # dependencies
    dict(
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/dependencySchema'],
        SCHEMA_NAME = 'Dependencies',
        SCHEMA_TOKEN = '__dependencies',
        GENERIC_MEMBER = ('dependency', 'HdDependencySchema',
                          # We have custom code to get the data, so do not
                          # provide a GETTER.
                          # But we do need to have GENERIC_MEMBER to not
                          # provide an empty Builder().
                          dict(GETTER=False)),
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # subdivisionTags
    dict(
        SCHEMA_NAME = 'SubdivisionTags',
        SCHEMA_TOKEN = 'subdivisionTags',
        IMPL_SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/meshSchema'],
        MEMBERS = [
            ('faceVaryingLinearInterpolation', T_TOKEN, {}),
            ('interpolateBoundary', T_TOKEN, {}),
            ('triangleSubdivisionRule', T_TOKEN, {}),
            ('cornerIndices', T_INTARRAY, {}),
            ('cornerSharpnesses', T_FLOATARRAY, {}),
            ('creaseIndices', T_INTARRAY, {}),
            ('creaseLengths', T_INTARRAY, {}),
            ('creaseSharpnesses', T_FLOATARRAY, {}),
        ],

        LOCATOR_PREFIX = 'HdMeshSchema::GetDefaultLocator()',
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # geomSubset
    dict(
        SCHEMA_NAME = 'GeomSubset',
        SCHEMA_TOKEN = 'geomSubset',
        MEMBERS = [
            ('type', T_TOKEN, {}),
            ('indices', T_INTARRAY, {}),
        ],

        STATIC_TOKEN_DATASOURCE_BUILDERS = [ # optional for shared token ds's
            ('type', ['typeFaceSet', 'typePointSet', 'typeCurveSet']),
        ],
        
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # mesh
    dict(
        SCHEMA_NAME = 'Mesh',
        SCHEMA_TOKEN = 'mesh',
        SCHEMA_INCLUDES =
            ['{{LIBRARY_PATH}}/meshTopologySchema',
             '{{LIBRARY_PATH}}/subdivisionTagsSchema'],
        
        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            ('topology', 'HdMeshTopologySchema', {}),
            ('subdivisionScheme', T_TOKEN, {}),
            ('subdivisionTags', 'HdSubdivisionTagsSchema', {}),
            ('doubleSided', T_BOOL, {}),
        ],

        ADD_DEFAULT_LOCATOR = True,

    ),

    #--------------------------------------------------------------------------
    # meshTopology
    dict(
        SCHEMA_NAME = 'MeshTopology',
        SCHEMA_TOKEN = 'topology',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/subdivisionTagsSchema'],
        MEMBERS = [
            ('faceVertexCounts', T_INTARRAY, {}),
            ('faceVertexIndices', T_INTARRAY, {}),
            ('holeIndices', T_INTARRAY, {}),
            ('orientation', T_TOKEN, {}),
        ],
        IMPL_SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/meshSchema'],
        LOCATOR_PREFIX = 'HdMeshSchema::GetDefaultLocator()',
        ADD_DEFAULT_LOCATOR = True,

        STATIC_TOKEN_DATASOURCE_BUILDERS = [ # optional for shared token ds's
            ('orientation', ['leftHanded', 'rightHanded']),
        ],
    ),

    #--------------------------------------------------------------------------
    # tetMesh
    dict(
        SCHEMA_NAME = 'TetMesh',
        SCHEMA_TOKEN = 'tetMesh',
        SCHEMA_INCLUDES =
            ['{{LIBRARY_PATH}}/tetMeshTopologySchema'],
        
        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            ('topology', 'HdTetMeshTopologySchema', {}),
            ('doubleSided', T_BOOL, {}),
        ],

        ADD_DEFAULT_LOCATOR = True,

    ),
    #--------------------------------------------------------------------------
    # tetMeshTopology
    dict(
        SCHEMA_NAME = 'TetMeshTopology',
        SCHEMA_TOKEN = 'topology',
        MEMBERS = [
            ('tetVertexIndices', T_VEC4IARRAY, dict(ADD_LOCATOR = True)),
            ('surfaceFaceVertexIndices', T_VEC3IARRAY, dict(ADD_LOCATOR = True)),
            ('orientation', T_TOKEN, {}),
        ],
        IMPL_SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/tetMeshSchema'],
        LOCATOR_PREFIX = 'HdTetMeshSchema::GetDefaultLocator()',
        ADD_DEFAULT_LOCATOR = True,

        STATIC_TOKEN_DATASOURCE_BUILDERS = [ # optional for shared token ds's
            ('orientation', ['leftHanded', 'rightHanded']),
        ],
    ),

    #--------------------------------------------------------------------------
    # nurbsPatch
    dict(
        SCHEMA_NAME = 'NurbsPatch',
        SCHEMA_TOKEN = 'nurbsPatch',
        SCHEMA_INCLUDES =
            ['{{LIBRARY_PATH}}/nurbsPatchTrimCurveSchema'],
        MEMBERS = [
            ('uVertexCount', T_INT, {}),
            ('vVertexCount', T_INT, {}),
            ('uOrder', T_INT, {}),
            ('vOrder', T_INT, {}),
            ('uKnots', T_DOUBLEARRAY, {}),
            ('vKnots', T_DOUBLEARRAY, {}),
            ('uForm', T_TOKEN, {}),
            ('vForm', T_TOKEN, {}),
            ('uRange', T_VEC2D, {}),
            ('vRange', T_VEC2D, {}),
            ('trimCurve', 'HdNurbsPatchTrimCurveSchema', {}),
            ('orientation', T_TOKEN, {}),
            ('doubleSided', T_BOOL, {}),
        ],
        
        ADD_DEFAULT_LOCATOR = True,

        STATIC_TOKEN_DATASOURCE_BUILDERS = [
            ('form', ['open', 'closed', 'periodic']),
            ('orientation', ['leftHanded', 'rightHanded']),
        ],
    ),

    #--------------------------------------------------------------------------
    # nurbsPatchTrimCurve
    dict(
        SCHEMA_NAME = 'NurbsPatchTrimCurve',
        SCHEMA_TOKEN = 'trimCurve',
        MEMBERS = [
            ('counts', T_INTARRAY, {}),
            ('orders', T_INTARRAY, {}),
            ('vertexCounts', T_INTARRAY, {}),
            ('knots', T_DOUBLEARRAY, {}),
            ('ranges', T_VEC2DARRAY, {}),
            ('points', T_VEC3DARRAY, {}),
        ],
        IMPL_SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/nurbsPatchSchema'],
        LOCATOR_PREFIX = 'HdNurbsPatchSchema::GetDefaultLocator()',
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # basisCurves
    dict(
        SCHEMA_NAME = 'BasisCurves',
        SCHEMA_TOKEN = 'basisCurves',
        SCHEMA_INCLUDES =
            ['{{LIBRARY_PATH}}/basisCurvesTopologySchema'],

        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            ('topology', 'HdBasisCurvesTopologySchema', {}),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # basisCurvesTopology
    dict(
        SCHEMA_NAME = 'BasisCurvesTopology',
        SCHEMA_TOKEN = 'topology',
        IMPL_SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/basisCurvesSchema'],
        LOCATOR_PREFIX = 'HdBasisCurvesSchema::GetDefaultLocator()',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('curveVertexCounts', T_INTARRAY, {}),
            ('curveIndices', T_INTARRAY, {}),
            ('basis', T_TOKEN, {}),
            ('type', T_TOKEN, {}),
            ('wrap', T_TOKEN, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # nurbsCurves
    dict(
        SCHEMA_NAME = 'NurbsCurves',
        SCHEMA_TOKEN = 'nurbsCurves',
        MEMBERS = [
            ('curveVertexCounts', T_INTARRAY, {}),
            ('order', T_INTARRAY, {}),
            ('knots', T_DOUBLEARRAY, {}),
            ('ranges', T_VEC2DARRAY, {}),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # primvar
    dict(
        SCHEMA_NAME = 'Primvar',
        MEMBERS = [
            ('primvarValue', T_SAMPLED,
             dict(DOC = '''
                If the primvar does not have indices, GetPrimvarValue() and
                GetIndexedPrimvarValue() will return the same thing.
                If the primvar does has indices, GetPrimvarValue() will return the 
                flattened value, while GetIndexedPrimvarValue() will return the
                unflattened value.''',
                  # We provide a custom getter for this.
                  GETTER = False)),
            ('indexedPrimvarValue', T_SAMPLED,
                  # We provide a custom getter for this.
             dict(GETTER = False)),
            ('indices', T_INTARRAY, {}),
            ('interpolation', T_TOKEN, {}),
            ('role', T_TOKEN, {}),
        ],
        EXTRA_TOKENS = [
            'transform',
        ],

        STATIC_TOKEN_DATASOURCE_BUILDERS = [ # optional for shared token ds's
            ('interpolation', [
                'constant',
                'uniform',
                'varying',
                'vertex',
                'faceVarying',
                'instance',
                ]),
            ('role', [
                'point',
                'normal',
                'vector',
                'color',
                'pointIndex',
                'edgeIndex',
                'faceIndex',
                'textureCoordinate',
                ]),
        ],
    ),

    #--------------------------------------------------------------------------
    # primvars
    dict(
        SCHEMA_NAME = 'Primvars',
        SCHEMA_TOKEN = 'primvars',
        ADD_DEFAULT_LOCATOR = True,
        GENERIC_MEMBER = ('primvar', 'HdPrimvarSchema', {}),
        MEMBERS = [
            ('ALL_MEMBERS', 'HdPrimvarSchema',
             # We want locators but no Getters for these primvars.
             dict(GETTER = False,
                  ADD_LOCATOR = True)),
            ('points', 'HdPrimvarSchema', {}),
            ('normals', 'HdPrimvarSchema', {}),
            ('widths', 'HdPrimvarSchema', {}),
        ],

        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/primvarSchema'],
    ),

    #--------------------------------------------------------------------------
    # xform
    dict(
        SCHEMA_NAME = 'Xform',
        SCHEMA_TOKEN = 'xform',
        MEMBERS = [
            ('matrix', T_MATRIX, {}),
            ('resetXformStack', T_BOOL,
             dict(DOC = '''
                The "resetXformStack" flag tells consumers that this transform
                doesn't inherit from the parent prim's transform.''')),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # visibility
    dict(
        SCHEMA_NAME = 'Visibility',
        SCHEMA_TOKEN = 'visibility',
        MEMBERS = [
            ('visibility', T_BOOL, {}),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # purpose
    dict(
        SCHEMA_NAME = 'Purpose',
        SCHEMA_TOKEN = 'purpose',
        MEMBERS = [
            ('purpose', T_TOKEN, {}),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # extent
    dict(
        SCHEMA_NAME = 'Extent',
        SCHEMA_TOKEN = 'extent',
        MEMBERS = [
            ('min', T_VEC3D, {}),
            ('max', T_VEC3D, {}),
            
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # materialNode
    dict(
        SCHEMA_NAME = 'MaterialNode',
        DOC = '''
            The MaterialNode schema is a container schema that defines a 
            particular node in a material network.

            A material node defines its connections to other nodes via the
            "inputConnections" member. For example, "albedo" would define that 
            it receives its value from its connection to the node 
            "Color_UnPreMult" and the output "resultRGB" with the following data
            sources:
                
            ds at: material/<renderContext>/nodes/MaterialLayer/inputConnections
                /albedo/[0]/upstreamNodePath = Color_UnPreMult

            ds at: material/<renderContext>/nodes/MaterialLayer/inputConnections
                /albedo/[0]/upstreamNodeOutputName = resultRGB
            ''',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('parameters', 'HdMaterialNodeParameterContainerSchema', 
             dict(DOC = '''
                Maps parameter names to node parameters. Each node parameter
                is a container that is defined by the MaterialNodeParameter
                schema. Note that parameters are inputs that supply their value 
                directly.
                ''')),
            ('inputConnections', 'HdMaterialConnectionVectorContainerSchema', 
             dict(DOC = '''
                Maps input names to vectors of connections. Each connection is
                defined by the MaterialConnection schema. Note that 
                inputConnections are inputs that get their value from data flow 
                over the connection.  
                ''')),
            ('nodeIdentifier', T_TOKEN,
             dict(DOC = '''
                This identifies the shader the node represents. The
                renderContextNodeIdentifier container can store alternative
                values for this. A consumer which is interested in a specific
                render context should check for that token within
                renderContextNodeIdentifiers and fall back on this value in its
                absence.''')),
            ('renderContextNodeIdentifiers', T_CONTAINER,
             dict(DOC = '''
                A shading node can hold a nodeIdentifier value for multiple
                render contexts at once. This allows multiple renderer target
                representations to coexist in the same renderable scene. The
                contents of this container are alternate possible values for
                nodeIdentifier.
                A consumer which is interested in a specific
                render context should check for that token within
                this container and fall back on nodeIdentifier in its
                absence.''')),
            ('nodeTypeInfo', T_CONTAINER,
             dict(DOC = '''
                Rather than having an identifier, a shader can be specified
                by other information.''')),
        ],
    ),

    #--------------------------------------------------------------------------
    # materialNodeParameter
    dict(
        SCHEMA_NAME = 'MaterialNodeParameter',
        DOC = '''
            The MaterialNodeParameter schema defines the value data source for 
            the parameter.
            ''',
        MEMBERS = [
            ('value', T_SAMPLED, {}),
            # Parameter Metadata
            ('colorSpace', T_TOKEN, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # materialConnection
    dict(
        SCHEMA_NAME = 'MaterialConnection',
        DOC = '''
            The MaterialConnection schema defines an upstream connected node and
            output.

            See MaterialNode schema's documentation on its
            'inputConnections' member for an example.
            ''',
        MEMBERS = [
            ('upstreamNodePath', T_TOKEN, {}),
            ('upstreamNodeOutputName', T_TOKEN, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # materialInterfaceMapping
    dict(
        SCHEMA_NAME = 'MaterialInterfaceMapping',
        DOC = '''
            The MaterialInterfaceMapping schema identifies a material node
            parameter using its two members 'nodePath' and 'inputName'.  
            
            See MaterialNetwork schema's documentation on its 
            'interfaceMappings' member for an example.
            ''',
        MEMBERS = [
            ('nodePath', T_TOKEN, {}),
            ('inputName', T_TOKEN, {})
        ],
    ),

    #--------------------------------------------------------------------------
    # materialNetwork
    dict(
        SCHEMA_NAME = 'MaterialNetwork',
        DOC = '''
            The MaterialNetwork schema is a container schema that defines a
            material for a specific render context. A network is composed of 
            nodes, terminals, and interface mappings.    

            Interface mappings define the material's public UI. For example, the
            following data sources define a public UI "globalVal" that maps to 
            two different node parameters:
                
            ds at: material/<renderContext>/interfaceMappings/globalVal/[0]/
                nodePath = Color_Manipulate

            ds at: material/<renderContext>/interfaceMappings/globalVal/[0]/
                inputName = adjustVal

            ds at: material/<renderContext>/interfaceMappings/globalVal/[1]/
                nodePath = Color_RetargetLayer

            ds at: material/<renderContext>/interfaceMappings/globalVal/[1]/
                inputName = valRemapAmount
                
            The above means that the "globalVal" public UI name maps to the
            following parameter data sources at:
                
            ds at: material/<renderContext>/nodes/Color_Manipulate/parameters/
                adjustVal 
                
            ds at: material/<renderContext>/nodes/Color_RetargetLayer/
                parameters/valRemapAmount

            See also the Material schema documentation for ASCII art diagram.
            ''',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('nodes', 'HdMaterialNodeContainerSchema', 
             dict(DOC = '''
                Maps node names to material nodes. Each material node is a
                container that is defined by the MaterialNode schema. The
                topology of the network is expressed by the connections found on
                each material node.
                ''')),
            ('terminals', 'HdMaterialConnectionContainerSchema', 
             dict(DOC = '''
                Maps terminal names to material connections. Each connection
                is a container defined by the MaterialConnection schema.
                ''')),
            ('interfaceMappings', 'HdMaterialInterfaceMappingsContainerSchema', 
             dict(DOC = '''
                Maps interface names (public UI names) to vectors of material 
                node parameters. Each mapped material node parameter is a 
                container defined by the InterfaceMappings schema.
                ''')),
        ],
    ),

    #--------------------------------------------------------------------------
    # material
    dict(
        SCHEMA_NAME = 'Material',
        DOC = '''
            The Material schema is a container schema that provides the correct
            material definition per render context.

            For example, a material may specify several render contexts
            like the universalRenderContext (""), Renderman ("ri"), 
            Storm ("glslfx"), etc. Each render context will then provide the 
            specific definition for the renderer, which is defined by the
            MaterialNetwork schema. The universalRenderContext applies to all
            renderers.

            See "Custom Code: Schema Methods" section for ASCII art diagram.
            ''',
        SCHEMA_TOKEN = 'material',
        EXTRA_TOKENS = [
            '(universalRenderContext, "")',
        ],
        ADD_DEFAULT_LOCATOR = True,

        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/materialNetworkSchema'],

        GENERIC_MEMBER = (
            'materialNetwork', 'HdMaterialNetworkSchema',
            # We provide a custom getter for the material network
            # to fallback to the universalRenderContext.
            dict(GETTER = False))
    ),

    #--------------------------------------------------------------------------
    # materialOverride
    dict(
        SCHEMA_NAME = 'MaterialOverride',
        DOC = '''
            The MaterialOverride schema allows overrides to be made to the 
            material's public UI. Overrides can be applied to both material or 
            geometry scene index prim locations.

            The following is an example of a material override. The data
            source to author an override on the public UI name 
            "globalSpecularKface" would look like this:

            ds at: materialOverride/interfaceValues/globalSpecularKface/value =
                0.666

            There needs to be an interface mapping defined for 
            "globalSpecularKface", which could look like this:

            ds at: material/<renderContext>/interfaceMappings/
                globalSpecularKface/[0]/nodePath = MaterialLayer
                
            ds at: material/<renderContext>/interfaceMappings/
                globalSpecularKface/[0]/inputName = specularKface

            The above means that the "globalSpecularKface" public UI name will 
            map to the node parameter "specularKface", and for example, this 
            node parameter may already have a data source for its value:

            ds at: material/<renderContext>/nodes/MaterialLayer/parameters/
                specularKface/value = 0.222

            After resolving the material override, the data source of the 
            node parameter's value is replaced by the overriding value data
            source.

            ds at: material/<renderContext>/nodes/MaterialLayer/parameters/
                specularKface/value = 0.666

            Note that the MaterialOverride schema does not specify a render 
            context token because material overrides are high-level and do not 
            need to know about implementation details--they just need to specify
            an overriding data source. By contrast, the contents of a material 
            network do specify a render context token in order to define the 
            material nodes and interface mappings--you can imagine that a 
            Renderman vs Storm implementation of a material network would be 
            quite different.    

            See also the Material schema documentation for ASCII art diagram.
            ''',
        SCHEMA_TOKEN = 'materialOverride',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        ADD_DEFAULT_LOCATOR = True,
        
        MEMBERS = [
            ('interfaceValues', 'HdMaterialNodeParameterContainerSchema', 
             dict(DOC = '''
                Maps interface names (ie. public UI names) to overriding
                data sources that follow the MaterialNodeParameter schema.
                ''')),
        ],
    ),

    #--------------------------------------------------------------------------
    # materialBinding
    dict(
        SCHEMA_NAME = 'MaterialBinding',
        MEMBERS = [
            ('path', T_PATH, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # materialBindings
    dict(
        SCHEMA_NAME = 'MaterialBindings',
        SCHEMA_TOKEN = 'materialBindings',
        EXTRA_TOKENS = [
            '(allPurpose, "")',
        ],
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/materialBindingSchema'],
        GENERIC_MEMBER = (
            'materialBinding', 'HdMaterialBindingSchema',
            # We provide a custom getter falling back to the allPurpose.
            dict(GETTER = False)),
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # volumeFieldBinding
    dict(
        SCHEMA_NAME = 'VolumeFieldBinding',
        SCHEMA_TOKEN = 'volumeFieldBinding',
        ADD_DEFAULT_LOCATOR = True,
        GENERIC_MEMBER = ('volumeFieldBinding', T_PATH, {}),
    ),

    #--------------------------------------------------------------------------
    # coordSysBinding
    dict(
        SCHEMA_NAME = 'CoordSysBinding',
        SCHEMA_TOKEN = 'coordSysBinding',
        ADD_DEFAULT_LOCATOR = True,
        GENERIC_MEMBER = ('coordSysBinding', T_PATH, {}),
    ),

    #--------------------------------------------------------------------------
    # coordSys
    dict(
        SCHEMA_NAME = 'CoordSys',
        SCHEMA_TOKEN = 'coordSys',
        MEMBERS = [
            ('name', T_TOKEN, {}),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # instancedBy
    dict(
        SCHEMA_NAME = 'InstancedBy',
        DOC = '''A schema marking a prim as instanced by another prim.

                 Many renderers need to know not what prototypes an instancer has, but
                 rather what instancers a prototype has; this is encoded in
                 "instancedBy".  A prim is "instancedBy" /Instancer if /Instancer has
                 a prototype path that's a parent of the prim.  A complicating exception is
                 if /A instances /A/B, which instances /A/B/C, we don't consider /A to be
                 instancing /A/B/C directly; this is to support nested explicit instancing
                 of things like leaves/trees/forests.

                 This value is computed based on the instancer topology of instancer prims in
                 the scene.

                 Note: if multiple instancers reference a prototype, it's possible for
                 instancedBy to contain multiple entries.  Some renderers may be able to
                 read this directly, but some may need to duplicate prims with an op so that
                 each prim has a single instancer, depending on how the renderer exposes
                 instancing.''',
        SCHEMA_TOKEN = 'instancedBy',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('paths', T_PATHARRAY, dict(ADD_LOCATOR = True)),
            ('prototypeRoots', T_PATHARRAY, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # instance
    dict(
        SCHEMA_NAME = 'Instance',
        SCHEMA_TOKEN = 'instance',
        ADD_DEFAULT_LOCATOR = True,
        DOC = '''This schema can be considered the opposite of
                 instancerTopology's "instanceLocations".  When the scene
                 coalesces scene prims into multiple instances of a single
                 prototype, it inserts "instance" prims at the site of
                 de-duplication.  The instancer prim added to manage the
                 prototype uses "instanceLocations" to point back to all of
                 these instance prims.

                 The instance prims aren't directly useful for rendering but
                 can be useful for scene processing and data aggregation.''',
        MEMBERS = [
            ('instancer', T_PATH,
             dict(DOC = '''
                Path to instancer for which a (sub-)entry was added to
                its instancerTopology's instanceIndices during
                instance aggregation to account for this instance.
                Note that instanceIndices is nested, that is a vector
                data source containing integer arrays, one for each
                prototype the instancer is instancing. Thus, we need
                two indices to identify the entry: prototypeIndex is the
                outer index and instanceIndex the inner index.''')),
            ('prototypeIndex', T_INT,
             dict(DOC = '''
                Index into vector data source at
                instancer's instancerTopology's instanceIndices
                to find entry corresponding to this instance.''')),
            ('instanceIndex', T_INT,
             dict(DOC = '''
                Index into int array within the vector data source at
                instancer's instancerTopology's instanceIndices
                to find entry corresponding to this instance.''')),
        ],
    ),

    #--------------------------------------------------------------------------
    # instancerTopology
    dict(
        SCHEMA_NAME = 'InstancerTopology',
        DOC = '''Since the instancing schema is complicated:

                 An instancer is a prim at a certain scenegraph location that causes other
                 prims to be duplicated.  The instancer can also hold instance-varying data
                 like constant primvars or material relationships.

                 The important things an instancer has is:

                 1.) Instancer topology, describing how exactly the prims are duplicated;

                 2.) Instance-rate data, meaning data that varies per instance, such as
                     primvars or material bindings.

                 If an instancer causes prims "/A" and "/B" to be duplicated, we encode that
                 by setting prototypes = ["/A", "/B"].  Note that "/A" and "/B" can be
                 subtrees, not direct gprims.  instanceIndices encodes both multiplicity
                 and position in arrays of instance-rate data, per prototype path; if
                 instanceIndices = { [0,2], [1] }, then we draw /A twice (with instance
                 primvar indices 0 and 2); and /B once (with instance primvar index 1).
                 Mask is an auxiliary parameter that can be used to deactivate certain
                 instances; mask = [true, true, false] would disable the
                 second copy of "/A".  An empty mask array is the same as all-true.

                 Scenes generally specify instancing in one of two ways:

                 1.) Explicit instancing: prim /Instancer wants to draw its subtree at
                     an array of locations.  This is a data expansion form.

                 2.) Implicit instancing: prims /X and /Y are marked as being identical,
                     and scene load replaces them with a single prim and an instancer.
                     This is a data coalescing form.

                 For implicit instancing, we want to know the original paths of /X and /Y,
                 for doing things like resolving inheritance.  This is encoded in the
                 "instanceLocations" path, while the prototype prims (e.g. /_Prototype/Cube,
                 the deduplicated version of /X/Cube and /Y/Cube) is encoded in the
                 "prototypes" path.

                 For explicit instancing, the "instanceLocations" attribute is meaningless
                 and should be left null.''',
        SCHEMA_TOKEN = 'instancerTopology',
        ADD_DEFAULT_LOCATOR = True,
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('prototypes', T_PATHARRAY, {}),
            ('instanceIndices', 'HdIntArrayVectorSchema', {}),
            ('mask', T_BOOLARRAY, {}),
            ('instanceLocations', T_PATHARRAY, {}),

        ],
    ),

    #--------------------------------------------------------------------------
    # legacyDisplayStyle
    dict(
        SCHEMA_NAME = 'LegacyDisplayStyle',
        SCHEMA_TOKEN = 'displayStyle',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('refineLevel', T_INT, {}),
            ('flatShadingEnabled', T_BOOL, {}),
            ('displacementEnabled', T_BOOL, {}),
            ('occludedSelectionShowsThrough', T_BOOL, {}),
            ('pointsShadingEnabled', T_BOOL, {}),
            ('materialIsFinal', T_BOOL, {}),
            ('shadingStyle', T_TOKEN, {}),
            ('reprSelector', T_TOKENARRAY,
             dict(ADD_LOCATOR = True)),
            ('cullStyle', T_TOKEN,
             dict(ADD_LOCATOR = True)),
        ],
    ),

    #--------------------------------------------------------------------------
    # light
    dict(
        SCHEMA_NAME = 'Light',
        SCHEMA_TOKEN = 'light',
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # imageShader
    dict(
        SCHEMA_NAME = 'ImageShader',
        SCHEMA_TOKEN = 'imageShader',
        ADD_DEFAULT_LOCATOR = True,
        SCHEMA_INCLUDES = [
            '{{LIBRARY_PATH}}/schemaTypeDefs',
            '{{LIBRARY_PATH}}/materialNetworkSchema'],
        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            ('enabled', T_BOOL, {}),
            ('priority', T_INT, {}),
            ('filePath', T_STRING, {}),
            ('constants', 'HdSampledDataSourceContainerSchema', {}),
            ('materialNetwork', 'HdMaterialNetworkSchema', {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # renderBuffer
    dict(
        SCHEMA_NAME = 'RenderBuffer',
        SCHEMA_TOKEN = 'renderBuffer',
        MEMBERS = [
            ('dimensions', T_VEC3I, {}),
            ('format', T_FORMAT, {}),
            ('multiSampled', T_BOOL, {}),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # renderPass
    dict(
        SCHEMA_NAME = 'RenderPass',
        SCHEMA_TOKEN = 'renderPass',
        ADD_DEFAULT_LOCATOR = True,
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            ('passType', T_TOKEN, {}),
            ('renderSource', T_PATH, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # renderSettings
    dict(
        SCHEMA_NAME = 'RenderSettings',
        SCHEMA_TOKEN = 'renderSettings',
        ADD_DEFAULT_LOCATOR = True,
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            ('namespacedSettings', T_CONTAINER, {}),
            ('active', T_BOOL, {}),
            ('renderProducts', 'HdRenderProductVectorSchema', {}),
            ('includedPurposes', T_TOKENARRAY, {}),
            ('materialBindingPurposes', T_TOKENARRAY, {}),
            ('renderingColorSpace', T_TOKEN, {}),
            ('shutterInterval', T_VEC2D,
             dict(DOC = '''
                Frame-relative time interval representing the sampling window for 
                data relevant to motion blur. Renderers can use this interval when
                querying time-sampled data (e.g., xforms, points, velocities, ...)
                to simulate motion blur effects.
            
                Note: This closely relates to the (frame-relative) shutter
                      interval of a camera specified via shutter open and close
                      times and is expected to span the union of the shutter
                      intervals of cameras used in generating the render
                      artifacts.''')),
        ],
    ),

    #--------------------------------------------------------------------------
    # renderProduct
    dict(
        SCHEMA_NAME = 'RenderProduct',
        SCHEMA_TOKEN = 'renderProduct',
        ADD_DEFAULT_LOCATOR = True,
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('path', T_PATH, {}), # scene prim path
            ('type', T_TOKEN, {}),
            ('name', T_TOKEN, {}), # output name
            ('resolution', T_VEC2I, dict(ADD_LOCATOR = True)),
            ('renderVars', 'HdRenderVarVectorSchema', dict(ADD_LOCATOR = True)),
            # Camera & Framing
            ('cameraPrim', T_PATH, {}),
            ('pixelAspectRatio', T_FLOAT, {}),
            ('aspectRatioConformPolicy', T_TOKEN, {}),
            ('apertureSize', T_VEC2F, {}),
            ('dataWindowNDC', T_VEC4F, {}), # XXX T_RANGE2F
            # Product specific overrides
            ('disableMotionBlur', T_BOOL, {}),
            ('disableDepthOfField', T_BOOL, {}),
            ('namespacedSettings', T_CONTAINER, dict(ADD_LOCATOR = True)),
        ],
    ),

    #--------------------------------------------------------------------------
    # renderVar
    dict(
        SCHEMA_NAME = 'RenderVar',
        SCHEMA_TOKEN = 'renderVar',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('path', T_PATH, {}), # scene prim path
            ('dataType', T_TOKEN, {}),
            ('sourceName', T_TOKEN, {}),
            ('sourceType', T_TOKEN, {}),
            # Var specific overrides
            ('namespacedSettings', T_CONTAINER, dict(ADD_LOCATOR = True)),
        ],
    ),

    #--------------------------------------------------------------------------
    # integrator
    dict(
        SCHEMA_NAME = 'Integrator',
        SCHEMA_TOKEN = 'integrator',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/materialNodeSchema'],
        MEMBERS = [
            ('resource', 'HdMaterialNodeSchema', dict(ADD_LOCATOR = True)),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # sampleFilter
    dict(
        SCHEMA_NAME = 'SampleFilter',
        SCHEMA_TOKEN = 'sampleFilter',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/materialNodeSchema'],
        MEMBERS = [
            ('resource', 'HdMaterialNodeSchema', dict(ADD_LOCATOR = True)),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # displayFilter
    dict(
        SCHEMA_NAME = 'DisplayFilter',
        SCHEMA_TOKEN = 'displayFilter',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/materialNodeSchema'],
        MEMBERS = [
            ('resource', 'HdMaterialNodeSchema', dict(ADD_LOCATOR = True)),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # system
    dict(
        SCHEMA_NAME = 'System',
        DOC = '''The {{ SCHEMA_CLASS_NAME }} specifies a container that will hold
                 "system" data.  Each piece of system data is identified by a key
                 within the container.  A piece of system data is evaluated at a
                 given location by walking up the namespace looking for a system 
                 container that contains the corresponding key.''',
        SCHEMA_TOKEN = 'system',
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # volumeField
    dict(
        SCHEMA_NAME = 'VolumeField',
        SCHEMA_TOKEN = 'volumeField',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('filePath', T_ASSETPATH, {}),
            ('fieldName', T_TOKEN, {}),
            ('fieldIndex', T_INT, {}),
            ('fieldDataType', T_TOKEN, {}),
            ('vectorDataRoleHint', T_TOKEN, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # camera
    dict(
        SCHEMA_NAME = 'Camera',
        SCHEMA_TOKEN = 'camera',
        SCHEMA_INCLUDES = [
            '{{LIBRARY_PATH}}/schemaTypeDefs',
            '{{LIBRARY_PATH}}/splitDiopterSchema',
            '{{LIBRARY_PATH}}/lensDistortionSchema'],
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('projection', T_TOKEN, {}),
            ('horizontalAperture', T_FLOAT, {}),
            ('verticalAperture', T_FLOAT, {}),
            ('horizontalApertureOffset', T_FLOAT, {}),
            ('verticalApertureOffset', T_FLOAT, {}),
            ('focalLength', T_FLOAT, {}),
            ('clippingRange', T_VEC2F, {}),
            ('clippingPlanes', T_VEC4DARRAY, {}),
            ('fStop', T_FLOAT, {}),
            ('focusDistance', T_FLOAT, {}),
            ('shutterOpen', T_DOUBLE, dict(ADD_LOCATOR = True)),
            ('shutterClose', T_DOUBLE, dict(ADD_LOCATOR = True)),
            ('exposure', T_FLOAT, {}),
            ('focusOn', T_BOOL, {}),
            ('dofAspect', T_FLOAT, {}),
            ('splitDiopter', 'HdSplitDiopterSchema', {}),
            ('lensDistortion', 'HdLensDistortionSchema', {}),
            ('namespacedProperties', 'HdSampledDataSourceContainerContainerSchema', dict(ADD_LOCATOR = True)),
        ],
        STATIC_TOKEN_DATASOURCE_BUILDERS = [ # optional for shared token ds's
            ('projection', ['perspective', 'orthographic']),
        ],
    ),

    #--------------------------------------------------------------------------
    # splitDiopter
    dict(
        SCHEMA_NAME = 'SplitDiopter',
        SCHEMA_TOKEN = 'splitDiopter',
        MEMBERS = [
            ('count', T_INT, {}),
            ('angle', T_FLOAT, {}),
            ('offset1', T_FLOAT, {}),
            ('width1', T_FLOAT, {}),
            ('focusDistance1', T_FLOAT, {}),
            ('offset2', T_FLOAT, {}),
            ('width2', T_FLOAT, {}),
            ('focusDistance2', T_FLOAT, {}),
        ],
        IMPL_SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/cameraSchema'],
        LOCATOR_PREFIX = 'HdCameraSchema::GetDefaultLocator()',
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # lensDistortion
    dict(
        SCHEMA_NAME = 'LensDistortion',
        SCHEMA_TOKEN = 'lensDistortion',
        MEMBERS = [
            ('type', T_TOKEN, {}),
            ('k1', T_FLOAT, {}),
            ('k2', T_FLOAT, {}),
            ('center', T_VEC2F, {}),
            ('anaSq', T_FLOAT, {}),
            ('asym', T_VEC2F, {}),
            ('scale', T_FLOAT, {}),
            ('ior', T_FLOAT, {}),
        ],
        IMPL_SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/cameraSchema'],
        LOCATOR_PREFIX = 'HdCameraSchema::GetDefaultLocator()',
        ADD_DEFAULT_LOCATOR = True,

        STATIC_TOKEN_DATASOURCE_BUILDERS = [ # optional for shared token ds's
            ('type', ['standard', 'fisheye']),
        ],
    ),

    #--------------------------------------------------------------------------
    # categories
    dict(
        SCHEMA_NAME = 'Categories',
        SCHEMA_TOKEN = 'categories',
        ADD_DEFAULT_LOCATOR = True,
    ),

    #--------------------------------------------------------------------------
    # instanceCategories
    dict(
        SCHEMA_NAME = 'InstanceCategories',
        SCHEMA_TOKEN = 'instanceCategories',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('categoriesValues', 'HdVectorDataSource', {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # extcomputation_primvar
    dict(
        SCHEMA_NAME = 'ExtComputationPrimvar',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/primvarSchema'],
        MEMBERS = [
            ('interpolation', T_TOKEN, {}),
            ('role', T_TOKEN, {}),
            ('sourceComputation', T_PATH, {}),
            ('sourceComputationOutputName', T_TOKEN, {}),
            ('valueType', T_TUPLE, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # extcomputation_primvars
    dict(
        SCHEMA_NAME = 'ExtComputationPrimvars',
        SCHEMA_TOKEN = 'extComputationPrimvars',
        ADD_DEFAULT_LOCATOR = True,
        GENERIC_MEMBER = ('extComputationPrimvar', 'HdExtComputationPrimvarSchema', {}),
        
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/extComputationPrimvarSchema'],
    ),

    #--------------------------------------------------------------------------
    # extcomputation_inputComputation
    dict(
        SCHEMA_NAME = 'ExtComputationInputComputation',
        MEMBERS = [
            ('sourceComputation', T_PATH, {}),
            ('sourceComputationOutputName', T_TOKEN, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # extcomputation_output
    dict(
        SCHEMA_NAME = 'ExtComputationOutput',
        MEMBERS = [
            ('valueType', T_TUPLE, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # extcomputation
    dict(
        SCHEMA_NAME = 'ExtComputation',
        SCHEMA_TOKEN = 'extComputation',
        ADD_DEFAULT_LOCATOR = True,
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            # inputValues should be a vector schema of typed data sources
            ('inputValues', 'HdSampledDataSourceContainerSchema', {}),
            ('inputComputations', 'HdExtComputationInputComputationContainerSchema', {}),
            ('outputs', 'HdExtComputationOutputContainerSchema', {}),
            ('glslKernel', T_STRING, {}),
            ('cpuCallback', 'HdExtComputationCpuCallbackDataSource', {}),
            ('dispatchCount', T_SIZET, {}),
            ('elementCount', T_SIZET, {}),
        ],
    ),
    
    #--------------------------------------------------------------------------
    # cube
    dict(
        SCHEMA_NAME = 'Cube',
        SCHEMA_TOKEN = 'cube',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('size', T_DOUBLE, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # sphere
    dict(
        SCHEMA_NAME = 'Sphere',
        SCHEMA_TOKEN = 'sphere',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('radius', T_DOUBLE, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # cone
    dict(
        SCHEMA_NAME = 'Cone',
        SCHEMA_TOKEN = 'cone',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('height', T_DOUBLE, {}),
            ('radius', T_DOUBLE, {}),
            ('axis', T_TOKEN, {}),
        ],

        STATIC_TOKEN_DATASOURCE_BUILDERS = [
            ('axis', ['X', 'Y', 'Z']),
        ],
    ),

    #--------------------------------------------------------------------------
    # cylinder
    dict(
        SCHEMA_NAME = 'Cylinder',
        SCHEMA_TOKEN = 'cylinder',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('height', T_DOUBLE, {}),
            # deprecated in favor of radiusTop and radiusBottom
            ('radius', T_DOUBLE, {}), 
            ('radiusTop', T_DOUBLE, {}),
            ('radiusBottom', T_DOUBLE, {}),
            ('axis', T_TOKEN, {}),
        ],

        STATIC_TOKEN_DATASOURCE_BUILDERS = [
            ('axis', ['X', 'Y', 'Z']),
        ],
    ),

    #--------------------------------------------------------------------------
    # capsule
    dict(
        SCHEMA_NAME = 'Capsule',
        SCHEMA_TOKEN = 'capsule',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('height', T_DOUBLE, {}),
            # deprecated in favor of radiusTop and radiusBottom
            ('radius', T_DOUBLE, {}), 
            ('radiusTop', T_DOUBLE, {}),
            ('radiusBottom', T_DOUBLE, {}),
            ('axis', T_TOKEN, {}),
        ],

        STATIC_TOKEN_DATASOURCE_BUILDERS = [
            ('axis', ['X', 'Y', 'Z']),
        ],

    ),
    
    #--------------------------------------------------------------------------
    # plane
    dict(
        SCHEMA_NAME = 'Plane',
        SCHEMA_TOKEN = 'plane',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('doubleSided', T_BOOL, {}),
            ('axis', T_TOKEN, {}),
            ('length', T_DOUBLE, {}),
            ('width', T_DOUBLE, {}),
        ],

        STATIC_TOKEN_DATASOURCE_BUILDERS = [
            ('axis', ['X', 'Y', 'Z']),
        ],
    ),

    #--------------------------------------------------------------------------
    # primOrigin
    dict(
        SCHEMA_NAME = 'PrimOrigin',
        SCHEMA_TOKEN = 'primOrigin',
        ADD_DEFAULT_LOCATOR = True,
        STATIC_LOCATOR_ACCESSORS = [
            ('scenePath', ['primOrigin', 'scenePath']),
        ],
        EXTRA_TOKENS = [
            'scenePath',
        ],
    ),

    #--------------------------------------------------------------------------
    # selection
    dict(
        SCHEMA_NAME = 'Selection',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/schemaTypeDefs'],
        MEMBERS = [
            ('fullySelected', T_BOOL, {}),
            ('nestedInstanceIndices', 'HdInstanceIndicesVectorSchema',
             dict(DOC = '''
                Starting with the outer most, list for each nesting
                level of instancing what instances are selected.''')),
        ],
    ),

    #--------------------------------------------------------------------------
    # instanceIndices
    dict(
        SCHEMA_NAME = 'InstanceIndices',
        MEMBERS = [
            ('instancer', T_PATH, {}),
            ('prototypeIndex', T_INT, {}),
            ('instanceIndices', T_INTARRAY, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # sceneGlobals
    dict(
        SCHEMA_NAME = 'SceneGlobals',
        DOC = '''The {{ SCHEMA_CLASS_NAME }} encapsulates "global" state to orchestrate a
                 render. It currently houses the active render settings
                 and pass prim paths that describe the information
                 necessary to generate images from a single invocation
                 of a renderer, and the active time sample range and current  
                 frame number that may be relevant to downstream scene indices 
                 (e.g. procedural evaluation).

                 We shall use the convention of a container data source at the root prim
                 of the scene index that is populated with this global state.
                 The renderer and downstream scene indices can query it to configure their
                 behavior as necessary.''',
        SCHEMA_TOKEN = 'sceneGlobals',
        ADD_DEFAULT_LOCATOR = True,
        MEMBERS = [
            ('ALL_MEMBERS', '', dict(ADD_LOCATOR = True)),
            ('activeRenderPassPrim', T_PATH, {}),
            ('activeRenderSettingsPrim', T_PATH, {}),
            ('startTimeCode', T_DOUBLE, {}),
            ('endTimeCode', T_DOUBLE, {}),
            ('currentFrame', T_DOUBLE, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # renderCapabilities
    dict(
        SCHEMA_NAME = 'RenderCapabilities',
        MEMBERS = [
            ('motionBlur', T_BOOL, {}),
        ],
    ),

    #--------------------------------------------------------------------------
    # collections
    dict(
        SCHEMA_NAME = 'Collections',
        DOC = '''The {{ SCHEMA_CLASS_NAME }} specifies a wrapper container
                 for collection entries with the key being the collection name.
              ''',
        SCHEMA_TOKEN = 'collections',
        SCHEMA_INCLUDES = ['{{LIBRARY_PATH}}/collectionSchema'],
        GENERIC_MEMBER = (
            'collection', 'HdCollectionSchema', {}),
        ADD_DEFAULT_LOCATOR = True,
    ),

    # collection
    dict(
        SCHEMA_NAME = 'Collection',
        SCHEMA_TOKEN = 'collection',
        MEMBERS = [
            ('membershipExpression', T_PATHEXPRESSION, {}),
        ],
        ADD_DEFAULT_LOCATOR = True,
    ),
    #--------------------------------------------------------------------------
    dict(
        SCHEMA_NAME = 'ALL_SCHEMAS',
        LIBRARY_PATH = 'pxr/imaging/fabric'
    ),
    dict(
        SCHEMA_NAME = 'ArticulationRoot',
        SCHEMA_TOKEN = 'articulationRoot',
        MEMBERS = [
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'CollisionGroup',
        SCHEMA_TOKEN = 'collisionGroup',
        MEMBERS = [
            ('mergeGroupName', T_STRING, dict(ADD_LOCATOR = True)),
            ('invertFilteredGroups', T_BOOL, dict(ADD_LOCATOR = True)),
            ('filteredGroups', T_PATH, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'Collision',
        SCHEMA_TOKEN = 'collision',
        MEMBERS = [
            ('collisionEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('simulationOwner', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'DistanceJoint',
        SCHEMA_TOKEN = 'distanceJoint',
        MEMBERS = [
            ('minDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'DistanceJoint',
        SCHEMA_TOKEN = 'distanceJoint',
        MEMBERS = [
            ('minDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'Drive',
        SCHEMA_TOKEN = 'drive',
        MEMBERS = [
            ('type', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('maxForce', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('targetPosition', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('targetVelocity', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('damping', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('stiffness', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'FilteredPairs',
        SCHEMA_TOKEN = 'filteredPairs',
        MEMBERS = [
            ('filteredPairs', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'FixedJoint',
        SCHEMA_TOKEN = 'fixedJoint',
        MEMBERS = [
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'Joint',
        SCHEMA_TOKEN = 'joint',
        MEMBERS = [
            ('localPos0', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('localPos1', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('localRot0', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('localRot1', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('jointEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('collisionEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('excludeFromArticulation', T_BOOL, dict(ADD_LOCATOR = True)),
            ('breakForce', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('breakTorque', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('body0', T_PATHARRAY, dict(ADD_LOCATOR = True)),
            ('body1', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'Limit',
        SCHEMA_TOKEN = 'limit',
        MEMBERS = [
            ('low', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('high', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'Mass',
        SCHEMA_TOKEN = 'mass',
        MEMBERS = [
            ('mass', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('density', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('centerOfMass', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('diagonalInertia', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('principalAxes', T_QUATF, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysicsMaterial',
        SCHEMA_TOKEN = 'physicsMaterial',
        MEMBERS = [
            ('density', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('restitution', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('dynamicFriction', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('staticFriction', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'MeshCollision',
        SCHEMA_TOKEN = 'meshCollision',
        MEMBERS = [
            ('approximation', T_TOKEN, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PrismaticJoint',
        SCHEMA_TOKEN = 'prismaticJoint',
        MEMBERS = [
            ('axis', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('lowerLimit', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('upperLimit', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'RevoluteJoint',
        SCHEMA_TOKEN = 'revoluteJoint',
        MEMBERS = [
            ('axis', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('lowerLimit', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('upperLimit', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'RigidBody',
        SCHEMA_TOKEN = 'rigidBody',
        MEMBERS = [
            ('rigidBodyEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('kinematicEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('startsAsleep', T_BOOL, dict(ADD_LOCATOR = True)),
            ('velocity', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('angularVelocity', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('simulationOwner', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'Scene',
        SCHEMA_TOKEN = 'scene',
        MEMBERS = [
            ('gravityMagnitude', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('gravityDirection', T_VEC3F, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'SphericalJoint',
        SCHEMA_TOKEN = 'sphericalJoint',
        MEMBERS = [
            ('axis', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('coneAngle0Limit', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('coneAngle1Limit', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),

    ############# PhysX Schema Extension ###########################################################
    dict(
        SCHEMA_NAME = 'PhysxJointState',
        SCHEMA_TOKEN = 'physxJointState',
        MEMBERS = [
            ('position', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('velocity', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxArticulation',
        SCHEMA_TOKEN = 'physxArticulation',
        MEMBERS = [
            ('articulationEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enabledSelfCollisions', T_BOOL, dict(ADD_LOCATOR = True)),
            ('sleepThreshold', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('solverPositionIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('solverVelocityIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('stabilizationThreshold', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCamera',
        SCHEMA_TOKEN = 'physxCamera',
        MEMBERS = [
            ('alwaysUpdateEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCameraDrone',
        SCHEMA_TOKEN = 'physxCameraDrone',
        MEMBERS = [
            ('feedForwardVelocityGain', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followHeight', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('horizontalVelocityGain', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('positionOffset', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('rotationFilterTimeConstant', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('velocityFilterTimeConstant', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('verticalVelocityGain', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCameraFollow',
        SCHEMA_TOKEN = 'physxCameraFollow',
        MEMBERS = [
            ('cameraPositionTimeConstant', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('followMaxDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followMaxSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followMinDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followMinSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followTurnRateGain', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lookAheadMaxDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lookAheadMaxSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lookAheadMinDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lookAheadMinSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lookAheadTurnRateGain', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lookPositionHeight', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lookPositionTimeConstant', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('pitchAngle', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('pitchAngleTimeConstant', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('positionOffset', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('slowPitchAngleSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('slowSpeedPitchAngleScale', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('velocityNormalMinSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('yawAngle', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('yawRateTimeConstant', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCameraFollowVelocity',
        SCHEMA_TOKEN = 'physxCameraFollowVelocity',
        MEMBERS = [
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCameraFollowLook',
        SCHEMA_TOKEN = 'physxCameraFollowLook',
        MEMBERS = [
            ('downHillGroundAngle', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('downHillGroundPitch', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followReverseDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('followReverseSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('upHillGroundAngle', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('upHillGroundPitch', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('velocityBlendTimeConstant', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCharacterController',
        SCHEMA_TOKEN = 'physxCharacterController',
        MEMBERS = [
            ('climbingMode', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('contactOffset', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('invisibleWallHeight', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxJumpHeight', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('moveTarget', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('nonWalkableMode', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('scaleCoeff', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('slopeLimit', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('stepOffset', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('upAxis', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('volumeGrowth', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCollision',
        SCHEMA_TOKEN = 'physxCollision',
        MEMBERS = [
            ('contactOffset', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('minTorsionalPatchRadius', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('restOffset', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('torsionalPatchRadius', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxContactReport',
        SCHEMA_TOKEN = 'physxContactReport',
        MEMBERS = [
            ('threshold', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxConvexDecompositionCollision',
        SCHEMA_TOKEN = 'physxConvexDecompositionCollision',
        MEMBERS = [
            ('errorPercentage', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('hullVertexLimit', T_INT, dict(ADD_LOCATOR = True)),
            ('maxConvexHulls', T_INT, dict(ADD_LOCATOR = True)),
            ('minThickness', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('shrinkWrap', T_BOOL, dict(ADD_LOCATOR = True)),
            ('voxelResolution', T_INT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxConvexHullCollision',
        SCHEMA_TOKEN = 'physxConvexHullCollision',
        MEMBERS = [
            ('hullVertexLimit', T_INT, dict(ADD_LOCATOR = True)),
            ('minThickness', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxCookedData',
        SCHEMA_TOKEN = 'physxCookedData',
        MEMBERS = [
            ('buffer', T_INTARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxForce',
        SCHEMA_TOKEN = 'physxForce',
        MEMBERS = [
            ('force', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('forceEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('mode', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('torque', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('worldFrameEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxIsosurface',
        SCHEMA_TOKEN = 'physxIsosurface',
        MEMBERS = [
            ('anisotropyMax', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('anisotropyMin', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('anisotropyRadius', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('enableAnisotropy', T_BOOL, dict(ADD_LOCATOR = True)),
            ('gridFilteringPasses', T_STRING, dict(ADD_LOCATOR = True)),
            ('gridSmoothingRadiusRelativeToCellSize', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('gridSpacing', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('isoSurfaceEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('isosurfaceLevel', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('kernelRadius', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxSubgrids', T_INT, dict(ADD_LOCATOR = True)),
            ('maxTriangles', T_INT, dict(ADD_LOCATOR = True)),
            ('maxVertices', T_INT, dict(ADD_LOCATOR = True)),
            ('numMeshSmoothingPasses', T_INT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxJoint',
        SCHEMA_TOKEN = 'physxJoint',
        MEMBERS = [
            ('armature', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('enableProjection', T_BOOL, dict(ADD_LOCATOR = True)),
            ('jointFriction', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxJointVelocity', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxMaterial',
        SCHEMA_TOKEN = 'physxMaterial',
        MEMBERS = [
            ('compliantContactAccelerationSpring', T_BOOL, dict(ADD_LOCATOR = True)),
            ('compliantContactDamping', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('compliantContactStiffness', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('dampingCombineMode', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('frictionCombineMode', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('restitutionCombineMode', T_TOKEN, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxMeshMergeCollision',
        SCHEMA_TOKEN = 'physxMeshMergeCollision',
        MEMBERS = [
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxMimicJoint',
        SCHEMA_TOKEN = 'physxMimicJoint',
        MEMBERS = [
            ('gearing', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('offset', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('referenceJointAxis', T_TOKEN, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxPhysicsDistanceJoint',
        SCHEMA_TOKEN = 'physxPhysicsDistanceJoint',
        MEMBERS = [
            ('springDamping', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('springEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('springStiffness', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxPhysicsGearJoint',
        SCHEMA_TOKEN = 'physxPhysicsGearJoint',
        MEMBERS = [
            ('gearRatio', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('hinge0', T_PATHARRAY, dict(ADD_LOCATOR = True)),
            ('hinge1', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxPhysicsInstancer',
        SCHEMA_TOKEN = 'physxPhysicsInstancer',
        MEMBERS = [
            ('protoIndices', T_INTARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxPhysicsJointInstancer',
        SCHEMA_TOKEN = 'physxPhysicsJointInstancer',
        MEMBERS = [
            ('body0Indices', T_INTARRAY, dict(ADD_LOCATOR = True)),
            ('body1Indices', T_INTARRAY, dict(ADD_LOCATOR = True)),
            ('localPos0s', T_VEC3FARRAY, dict(ADD_LOCATOR = True)),
            ('localPos1s', T_VEC3FARRAY, dict(ADD_LOCATOR = True)),
            ('localRot0s', T_QUATFARRAY, dict(ADD_LOCATOR = True)),
            ('localRot1s', T_QUATFARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxPhysicsRackAndPinionJoint',
        SCHEMA_TOKEN = 'physxPhysicsRackAndPinionJoint',
        MEMBERS = [
            ('ratio', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('hinge', T_PATHARRAY, dict(ADD_LOCATOR = True)),
            ('prismatic', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxResidualReporting',
        SCHEMA_TOKEN = 'physxResidualReporting',
        MEMBERS = [
            ('maxResidualPositionIteration', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxResidualVelocityIteration', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('rmsResidualPositionIteration', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('rmsResidualVelocityIteration', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxRigidBody',
        SCHEMA_TOKEN = 'physxRigidBody',
        MEMBERS = [
            ('angularDamping', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('cfmScale', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('contactSlopCoefficient', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('disableGravity', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableCCD', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableGyroscopicForces', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableSpeculativeCCD', T_BOOL, dict(ADD_LOCATOR = True)),
            ('linearDamping', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lockedPosAxis', T_INT, dict(ADD_LOCATOR = True)),
            ('lockedRotAxis', T_INT, dict(ADD_LOCATOR = True)),
            ('maxAngularVelocity', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxContactImpulse', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxDepenetrationVelocity', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxLinearVelocity', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('retainAccelerations', T_BOOL, dict(ADD_LOCATOR = True)),
            ('sleepThreshold', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('solveContact', T_BOOL, dict(ADD_LOCATOR = True)),
            ('solverPositionIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('solverVelocityIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('stabilizationThreshold', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxScene',
        SCHEMA_TOKEN = 'physxScene',
        MEMBERS = [
            ('bounceThreshold', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('broadphaseType', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('collisionSystem', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('enableCCD', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableEnhancedDeterminism', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableExternalForcesEveryIteration', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableGPUDynamics', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableResidualReporting', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableSceneQuerySupport', T_BOOL, dict(ADD_LOCATOR = True)),
            ('enableStabilization', T_BOOL, dict(ADD_LOCATOR = True)),
            ('frictionCorrelationDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('frictionOffsetThreshold', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('frictionType', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('gpuCollisionStackSize', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuFoundLostAggregatePairsCapacity', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuFoundLostPairsCapacity', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuHeapCapacity', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuMaxDeformableSurfaceContacts', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuMaxHairContacts', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuMaxNumPartitions', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuMaxParticleContacts', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuMaxRigidContactCount', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuMaxRigidPatchCount', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuMaxSoftBodyContacts', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuTempBufferCapacity', T_INT, dict(ADD_LOCATOR = True)),
            ('gpuTotalAggregatePairsCapacity', T_INT, dict(ADD_LOCATOR = True)),
            ('invertCollisionGroupFilter', T_BOOL, dict(ADD_LOCATOR = True)),
            ('maxBiasCoefficient', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxPositionIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('maxVelocityIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('minPositionIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('minVelocityIterationCount', T_INT, dict(ADD_LOCATOR = True)),
            ('reportKinematicKinematicPairs', T_BOOL, dict(ADD_LOCATOR = True)),
            ('reportKinematicStaticPairs', T_BOOL, dict(ADD_LOCATOR = True)),
            ('solverType', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('timeStepsPerSecond', T_INT, dict(ADD_LOCATOR = True)),
            ('updateType', T_TOKEN, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxSceneQuasistatic',
        SCHEMA_TOKEN = 'physxSceneQuasistatic',
        MEMBERS = [
            ('enableQuasistatic', T_BOOL, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxSDFMeshCollision',
        SCHEMA_TOKEN = 'physxSDFMeshCollision',
        MEMBERS = [
            ('sdfBitsPerSubgridPixel', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('sdfEnableRemeshing', T_BOOL, dict(ADD_LOCATOR = True)),
            ('sdfMargin', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('sdfNarrowBandThickness', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('sdfResolution', T_INT, dict(ADD_LOCATOR = True)),
            ('sdfSubgridResolution', T_INT, dict(ADD_LOCATOR = True)),
            ('sdfTriangleCountReductionFactor', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxSphereFillCollision',
        SCHEMA_TOKEN = 'physxSphereFillCollision',
        MEMBERS = [
            ('fillMode', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('maxSpheres', T_INT, dict(ADD_LOCATOR = True)),
            ('seedCount', T_INT, dict(ADD_LOCATOR = True)),
            ('voxelResolution', T_INT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxSurfaceVelocity',
        SCHEMA_TOKEN = 'physxSurfaceVelocity',
        MEMBERS = [
            ('surfaceAngularVelocity', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('surfaceVelocity', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('surfaceVelocityEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
            ('surfaceVelocityLocalSpace', T_BOOL, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxTriangleMeshCollision',
        SCHEMA_TOKEN = 'physxTriangleMeshCollision',
        MEMBERS = [
            ('weldTolerance', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxTriangleMeshSimplificationCollision',
        SCHEMA_TOKEN = 'physxTriangleMeshSimplificationCollision',
        MEMBERS = [
            ('metric', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('weldTolerance', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxTrigger',
        SCHEMA_TOKEN = 'physxTrigger',
        MEMBERS = [
            ('enterScriptType', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('leaveScriptType', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('onEnterScript', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('onLeaveScript', T_TOKEN, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxTriggerState',
        SCHEMA_TOKEN = 'physxTriggerState',
        MEMBERS = [
            ('triggeredCollisions', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleAckermannSteering',
        SCHEMA_TOKEN = 'physxVehicleAckermannSteering',
        MEMBERS = [
            ('maxSteerAngle', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('strength', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('trackWidth', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('wheel0', T_INT, dict(ADD_LOCATOR = True)),
            ('wheel1', T_INT, dict(ADD_LOCATOR = True)),
            ('wheelBase', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicle',
        SCHEMA_TOKEN = 'physxVehicle',
        MEMBERS = [
            ('highForwardSpeedSubStepCount', T_INT, dict(ADD_LOCATOR = True)),
            ('lateralStickyTireDamping', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lateralStickyTireThresholdSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lateralStickyTireThresholdTime', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('limitSuspensionExpansionVelocity', T_BOOL, dict(ADD_LOCATOR = True)),
            ('longitudinalStickyTireDamping', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('longitudinalStickyTireThresholdSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('longitudinalStickyTireThresholdTime', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('lowForwardSpeedSubStepCount', T_INT, dict(ADD_LOCATOR = True)),
            ('minActiveLongitudinalSlipDenominator', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('minLateralSlipDenominator', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('minPassiveLongitudinalSlipDenominator', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('subStepThresholdLongitudinalSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('suspensionLineQueryType', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('vehicleEnabled', T_BOOL, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleAutoGearBox',
        SCHEMA_TOKEN = 'physxVehicleAutoGearBox',
        MEMBERS = [
            ('downRatios', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
            ('latency', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('upRatios', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleBrakes',
        SCHEMA_TOKEN = 'physxVehicleBrakes',
        MEMBERS = [
            ('maxBrakeTorque', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('torqueMultipliers', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
            ('wheels', T_INTARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleClutch',
        SCHEMA_TOKEN = 'physxVehicleClutch',
        MEMBERS = [
            ('strength', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleContext',
        SCHEMA_TOKEN = 'physxVehicleContext',
        MEMBERS = [
            ('longitudinalAxis', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('updateMode', T_TOKEN, dict(ADD_LOCATOR = True)),
            ('verticalAxis', T_TOKEN, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleController',
        SCHEMA_TOKEN = 'physxVehicleController',
        MEMBERS = [
            ('accelerator', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('brake0', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('brake1', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('steer', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('targetGear', T_INT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleDriveBasic',
        SCHEMA_TOKEN = 'physxVehicleDriveBasic',
        MEMBERS = [
            ('peakTorque', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleDriveStandard',
        SCHEMA_TOKEN = 'physxVehicleDriveStandard',
        MEMBERS = [
            ('gears', T_PATHARRAY, dict(ADD_LOCATOR = True)),
            ('engine', T_PATHARRAY, dict(ADD_LOCATOR = True)),
            ('autoGearBox', T_PATHARRAY, dict(ADD_LOCATOR = True)),
            ('clutch', T_PATHARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleEngine',
        SCHEMA_TOKEN = 'physxVehicleEngine',
        MEMBERS = [
            ('dampingRateFullThrottle', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('dampingRateZeroThrottleClutchDisengaged', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('dampingRateZeroThrottleClutchEngaged', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('idleRotationSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('maxRotationSpeed', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('moi', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('peakTorque', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('torqueCurve', T_VEC2F, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleGears',
        SCHEMA_TOKEN = 'physxVehicleGears',
        MEMBERS = [
            ('ratios', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
            ('ratioScale', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('switchTime', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleMultiWheelDifferential',
        SCHEMA_TOKEN = 'physxVehicleMultiWheelDifferential',
        MEMBERS = [
            ('averageWheelSpeedRatios', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
            ('torqueRatios', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
            ('wheels', T_INTARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleNonlinearCommandResponse',
        SCHEMA_TOKEN = 'physxVehicleNonlinearCommandResponse',
        MEMBERS = [
            ('commandValues', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
            ('speedResponses', T_VEC2FARRAY, dict(ADD_LOCATOR = True)),
            ('speedResponsesPerCommandValue', T_INTARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleSteering',
        SCHEMA_TOKEN = 'physxVehicleSteering',
        MEMBERS = [
            ('angleMultipliers', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
            ('maxSteerAngle', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('wheels', T_INTARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleSuspension',
        SCHEMA_TOKEN = 'physxVehicleSuspension',
        MEMBERS = [
            ('springDamperRate', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('springStrength', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('sprungMass', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('travelDistance', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleSuspensionCompliance',
        SCHEMA_TOKEN = 'physxVehicleSuspensionCompliance',
        MEMBERS = [
            ('suspensionForceAppPoint', T_VEC4FARRAY, dict(ADD_LOCATOR = True)),
            ('tireForceAppPoint', T_VEC4FARRAY, dict(ADD_LOCATOR = True)),
            ('wheelCamberAngle', T_VEC2FARRAY, dict(ADD_LOCATOR = True)),
            ('wheelToeAngle', T_VEC2FARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleTankController',
        SCHEMA_TOKEN = 'physxVehicleTankController',
        MEMBERS = [
            ('thrust0', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('thrust1', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleTankDifferential',
        SCHEMA_TOKEN = 'physxVehicleTankDifferential',
        MEMBERS = [
            ('numberOfWheelsPerTrack', T_INTARRAY, dict(ADD_LOCATOR = True)),
            ('thrustIndexPerTrack', T_INTARRAY, dict(ADD_LOCATOR = True)),
            ('trackToWheelIndices', T_INTARRAY, dict(ADD_LOCATOR = True)),
            ('wheelIndicesInTrackOrder', T_INTARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleTire',
        SCHEMA_TOKEN = 'physxVehicleTire',
        MEMBERS = [
            ('camberStiffness', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('frictionVsSlipGraph', T_VEC2FARRAY, dict(ADD_LOCATOR = True)),
            ('lateralStiffnessGraph', T_VEC2F, dict(ADD_LOCATOR = True)),
            ('longitudinalStiffness', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('restLoad', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleTireFrictionTable',
        SCHEMA_TOKEN = 'physxVehicleTireFrictionTable',
        MEMBERS = [
            ('defaultFrictionValue', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('frictionValues', T_FLOATARRAY, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleWheel',
        SCHEMA_TOKEN = 'physxVehicleWheel',
        MEMBERS = [
            ('dampingRate', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('mass', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('moi', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('radius', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('width', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleWheelAttachment',
        SCHEMA_TOKEN = 'physxVehicleWheelAttachment',
        MEMBERS = [
            ('index', T_INT, dict(ADD_LOCATOR = True)),
            ('suspensionFrameOrientation', T_QUATF, dict(ADD_LOCATOR = True)),
            ('suspensionFramePosition', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('suspensionTravelDirection', T_VEC3F, dict(ADD_LOCATOR = True)),
            ('wheelFrameOrientation', T_QUATF, dict(ADD_LOCATOR = True)),
            ('wheelFramePosition', T_VEC3F, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
    dict(
        SCHEMA_NAME = 'PhysxVehicleWheelController',
        SCHEMA_TOKEN = 'physxVehicleWheelController',
        MEMBERS = [
            ('brakeTorque', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('driveTorque', T_FLOAT, dict(ADD_LOCATOR = True)),
            ('steerAngle', T_FLOAT, dict(ADD_LOCATOR = True)),
        ],

        ADD_DEFAULT_LOCATOR = True,
    ),
]
