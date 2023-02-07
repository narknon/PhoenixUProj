#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeCreationSettings.h"
#include "WorldFXOctreeUnculledFX.h"
#include "WorldFXOctreeStack.generated.h"

class UWorldFXOctree;

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXOctreeStack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWorldFXOctree*> OctreeStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXOctreeCreationSettings CreationSettings;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXOctreeUnculledFX UnculledFX;
    
public:
    FWorldFXOctreeStack();
};

