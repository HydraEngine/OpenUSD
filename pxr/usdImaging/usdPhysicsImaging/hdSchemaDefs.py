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