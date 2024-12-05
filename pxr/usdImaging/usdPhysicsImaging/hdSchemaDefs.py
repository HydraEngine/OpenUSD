[
    dict(
        SCHEMA_NAME = 'ALL_SCHEMAS',
        LIBRARY_PATH = 'pxr/usdImaging/usdPhysicsImaging'
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
        SCHEMA_NAME = 'Material',
        SCHEMA_TOKEN = 'material',
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
]
