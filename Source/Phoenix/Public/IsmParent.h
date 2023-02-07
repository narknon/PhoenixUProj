#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IsmParent.generated.h"

class UStaticMesh;

UCLASS(Blueprintable)
class AIsmParent : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* InstancedMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HierarchicalISM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableISM;
    
    AIsmParent();
};

