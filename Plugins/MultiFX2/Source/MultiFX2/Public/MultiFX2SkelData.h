#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiFX2SkelData.generated.h"

class USkeletalMesh;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Editor)
class MULTIFX2_API UMultiFX2SkelData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USkeletalMesh*> ReferenceSkeletonArray;
    
    UMultiFX2SkelData();
};

