#pragma once
#include "CoreMinimal.h"
#include "HighContrastGameplayMarkupActorComponent.h"
#include "HighContrastGameplayMarkupOtherActorComponent.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHighContrastGameplayMarkupOtherActorComponent : public UHighContrastGameplayMarkupActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<AActor>> MarkupActors;
    
    UHighContrastGameplayMarkupOtherActorComponent();
};

