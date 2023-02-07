#pragma once
#include "CoreMinimal.h"
#include "SceneRigSocketEntry.generated.h"

class USceneRigProvider;

USTRUCT(BlueprintType)
struct FSceneRigSocketEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* SceneRigProvider;
    
    PHOENIX_API FSceneRigSocketEntry();
};

