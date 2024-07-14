GET NEXT LINE

le but = afficher les lignes séparées par un \n d'un document text.

	how ??

-lire ligne et mettre dans buffer.
-mettre ligne lu dans str temp
-voir si y a \n dans temp. ft_strchr.
	si oui, -imprimer du début jusqu'a \n, ft_substr;
		-décaler ce qu'il y a après \n au niveau temp[0], ft_substr;
	si non, continuer à concatener le buffer lu dans temp sauvegardé.