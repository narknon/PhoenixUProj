#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblPhysicalBodyManager.generated.h"

class UPhysicalBodyBlendChannel;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ABLECORE_API UAblPhysicalBodyManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> GlobalBlendedWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, UPhysicalBodyBlendChannel*> PhysicalBodyBlendChannelMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumBodies;
    
public:
    UAblPhysicalBodyManager();
};

