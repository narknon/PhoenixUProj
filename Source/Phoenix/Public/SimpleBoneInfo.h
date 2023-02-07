#pragma once
#include "CoreMinimal.h"
#include "SimpleBoneInfo.generated.h"

class USceneComponent;
class USkinnedMeshComponent;

USTRUCT(BlueprintType)
struct FSimpleBoneInfo {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkinnedMeshComponent* BoneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* NameNoneComponent;
    
public:
    PHOENIX_API FSimpleBoneInfo();
};

