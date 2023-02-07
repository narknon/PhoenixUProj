#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "Templates/SubclassOf.h"
#include "Object_ActorComponent.generated.h"

class UActorComponent;
class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObject_ActorComponent : public UObjectProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* ActorProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActorComponent> ComponentType;
    
    UObject_ActorComponent();
};

