#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "EExternalActorRole.h"
#include "Actor_External.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UActor_External : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EExternalActorRole Role;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RoleIndex;
    
    UActor_External();
};

