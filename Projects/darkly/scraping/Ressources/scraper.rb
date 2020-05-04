require 'nokogiri'
require 'open-uri'

BASE_URL = ('http://' + ARGV[0].to_s + '/.hidden/').freeze
README = 'README'.freeze
SPACE = ' '.freeze
TO_EXCLUDE = Regexp.union(['Demande', 'Non ce', 'Toujours', 'Tu veux'])
OUTPUT_FILE_NAME = 'flag'.freeze
USAGE = 'Usage:\n ruby scraper.rb [vm ip address]'.freeze

PARSE_PAGE = -> (page) { Nokogiri::HTML(page) }

def depth_search(url_prefix)
	return puts USAGE unless ARGV[0]

	page = open(url_prefix).read
	urls = PARSE_PAGE.call(page).css('a')[1..-1].map { |link| url_prefix + link }
	urls.each do |url|
		if (url.include? README)
			sleep 0.003
			content = open(url).read
			unless content[TO_EXCLUDE]
				File.open(OUTPUT_FILE_NAME, 'w') { |f| f.write(content) }
				puts 'Flag found !'
				exit!
			end
			return
		end
		depth_search(url)
	end
end

depth_search(BASE_URL)
