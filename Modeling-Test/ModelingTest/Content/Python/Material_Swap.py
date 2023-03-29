import unreal
import random

EAS = unreal.EditorActorSubsystem()
EAL = unreal.EditorAssetLibrary()
ELL = unreal.EditorLevelLibrary()
EFL = unreal.EditorFilterLibrary()

all_level_actors = EAS.get_all_level_actors()

meshActors = EFL.by_class(all_level_actors, unreal.StaticMeshActor)

default_mat = EAL.load_asset('/Game/StarterContent/Materials/M_Basic_Wall')

materials = [
    '/Game/KnowYourenemy/Materials/MAT_Emissive_Orange',
    '/Game/KnowYourenemy/Materials/MAT_Emissive_Green',
    '/Game/KnowYourenemy/Materials/MAT_Character_Eyes',
    '/Game/KnowYourenemy/Materials/MAT_Fresnel_Emissive',
    '/Game/KnowYourenemy/Materials/MAT_Pulse_Color',
    '/Game/KnowYourenemy/Materials/MAT_SpinningLava'
]

meshComps = []

def swap():
    
    cubes = []
    
    for x in meshActors:
        if 'Cube' in x.get_actor_label():
            cubes.append(x)
            
    for cube in cubes:
        comp = cube.get_component_by_class(type(unreal.StaticMeshComponent()))
        meshComps.append(comp)

    
    for y in meshComps:
        random_mat = EAL.load_asset(random.choice(materials))
        y.set_material(0, random_mat)
        
def resize():
    
    cubes = []
    
    for x in meshActors:
        if 'Cube' in x.get_actor_label():
            cubes.append(x)
            
    for cube in cubes:
        currentscale = cube.get_actor_scale3d()
        
        x = random.randrange(1, 4)
        
        newscale = (x,x,x)
        
        cube.set_actor_scale3d(newscale)
        
def reset():
    
    cubes = []
    
    for x in meshActors:
        if 'Cube' in x.get_actor_label():
            cubes.append(x)
            
    for cube in cubes:
        currentscale = cube.get_actor_scale3d()
        
        newscale = (1,1,1)
        
        cube.set_actor_scale3d(newscale)
        
        comp = cube.get_component_by_class(type(unreal.StaticMeshComponent()))
        meshComps.append(comp)

    
    for y in meshComps:
        y.set_material(0, default_mat)