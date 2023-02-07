#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ToolType.generated.h"

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TOOLSET_API UToolType : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_autoEquipTimeout;
    
    UToolType();
};

