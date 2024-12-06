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
]
